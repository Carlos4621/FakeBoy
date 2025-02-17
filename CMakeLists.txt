cmake_minimum_required(VERSION 3.10)
project(FakeBoy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir directorios
include_directories(include)

# Buscar GoogleTest
find_package(GTest REQUIRED)

# Buscar archivos fuente (sin incluir archivos de prueba ni main.cpp)
file(GLOB SRC_FILES "src/*.cpp")

# Crear ejecutable principal
add_executable(FakeBoy main.cpp ${SRC_FILES})

# Habilitar pruebas
enable_testing()

# Definir lista de pruebas
file(GLOB TEST_FILES "test/*.cpp")

# Crear ejecutable para pruebas
add_executable(tests ${TEST_FILES} ${SRC_FILES})

# Vincular GoogleTest
target_link_libraries(tests PRIVATE GTest::gtest_main)

# Incluir GoogleTest para descubrimiento automático de pruebas
include(GoogleTest)
gtest_discover_tests(tests)
