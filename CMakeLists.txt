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

include_directories(include)

find_package(GTest REQUIRED)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(FakeBoy main.cpp ${SRC_FILES})

enable_testing()

file(GLOB TEST_FILES "test/*/*.cpp" "test/*.cpp")

add_executable(tests ${TEST_FILES} ${SRC_FILES})

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

file(GLOB ASM_FILES "test/testingCartridges/*.asm")

foreach(ASM_FILE ${ASM_FILES})
    get_filename_component(ASM_NAME ${ASM_FILE} NAME_WE)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.gb
        COMMAND rgbasm -o ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.o ${ASM_FILE}
        COMMAND rgblink -o ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.gb ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.o
        DEPENDS ${ASM_FILE}
        COMMENT "Compilando ROM ${ASM_NAME}.gb"
    )
    list(APPEND ROM_FILES ${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.gb)
endforeach()

add_custom_target(rom ALL DEPENDS ${ROM_FILES})