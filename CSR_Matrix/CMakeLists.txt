cmake_minimum_required(VERSION 3.20)
project(slae_course)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE CSRMatrix_files "*.cpp" ".h")
add_library(CSR_Matrix ${CSRMatrix_files})