cmake_minimum_required(VERSION 3.20)
project(slae_course)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(slae_course ThreeDiagonalMatrix/threediagonal_matrix.cpp ThreeDiagonalMatrix/threediagonal_matrix.h ThreeDiagonalMatrix/main.cpp ThreeDiagonalMatrix/numbers_column.h ThreeDiagonalMatrix/progonka.cpp ThreeDiagonalMatrix/progonka.h ThreeDiagonalMatrix/numbers_column.cpp)
add_subdirectory(GTest)