project(Gtest)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE TESTS *.cpp)

add_executable(Google_Tests_run test_for_threediagonal_matrix.cpp)
add_test(NAME test COMMAND test_for_threediagonal_matrix.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main ThreeDiagonalMatrix CSR_Matrix)


add_executable(Google_Tests_run1 test_for_csr_matrix.cpp)
add_test(NAME test1 COMMAND test_for_csr_matrix.cpp)
target_link_libraries(Google_Tests_run1 gtest gtest_main ThreeDiagonalMatrix CSR_Matrix)