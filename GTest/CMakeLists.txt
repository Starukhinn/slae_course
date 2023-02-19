project(Gtest)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE TESTS "*.cpp")

add_executable(Google_Tests_run ${TESTS})

target_link_libraries(Google_Tests_run gtest gtest_main ThreeDiagonalMatrix CSR_Matrix)