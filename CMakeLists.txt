cmake_minimum_required(VERSION 3.20)
project(slae_course)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(slae_course 1st_hw/threediagonal_matrix.cpp 1st_hw/threediagonal_matrix.h 1st_hw/main.cpp 1st_hw/numbers_column.h 1st_hw/progonka.cpp 1st_hw/progonka.h 1st_hw/numbers_column.cpp)
add_subdirectory(GTest)