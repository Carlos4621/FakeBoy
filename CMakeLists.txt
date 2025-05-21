cmake_minimum_required(VERSION 3.25)
project(FakeBoy)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

find_program(CLANG_TIDY_EXE "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy encontrado: ${CLANG_TIDY_EXE}")
    set(CLANG_TIDY_OPTIONS
        "${CLANG_TIDY_EXE}"
        "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
        "-p=${CMAKE_BINARY_DIR}"
    )
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_OPTIONS}")
else()
    message(WARNING "clang-tidy no encontrado. Análisis estático desactivado.")
endif()

include_directories(include include/* test/test_CPU/TestingCPU test/test_CPU/commons)

find_package(GTest REQUIRED)

file(GLOB SRC_FILES "src/*.cpp" "src/*/*.cpp" "test/test_CPU/TestingCPU/*.cpp")

add_executable(FakeBoy main.cpp ${SRC_FILES})

target_compile_options(FakeBoy PRIVATE -Wall -Wextra -Wpedantic -fsanitize=address,undefined -fno-omit-frame-pointer)
target_link_options(FakeBoy PRIVATE -fsanitize=address,undefined)

enable_testing()

file(GLOB TEST_FILES "test/*/*.cpp" "test/*.cpp" "test/*/*/*.cpp")

add_executable(tests ${TEST_FILES} ${SRC_FILES})
# Desactivar clang-tidy específicamente para el target de tests
set_target_properties(tests PROPERTIES CXX_CLANG_TIDY "")

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

set(ASM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/test/testingCartridges/commons")

file(GLOB ASM_FILES "test/testingCartridges/*.asm" "test/testingCartridges/commons/*.asm")

foreach(ASM_FILE ${ASM_FILES})
    get_filename_component(ASM_NAME ${ASM_FILE} NAME_WE)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.gb
        COMMAND rgbasm -i "${ASM_INCLUDE_DIR}" -o ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.o ${ASM_FILE}
        COMMAND rgblink -o ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.gb ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.o
        DEPENDS ${ASM_FILE}
        COMMENT "Compilando ROM ${ASM_NAME}.gb"
    )
    list(APPEND ROM_FILES ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.gb)
endforeach()

add_custom_target(rom ALL DEPENDS ${ROM_FILES})