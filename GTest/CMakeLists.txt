# 'Google_test' is the subproject name
project(GTest)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(GTest_run test1.cpp)
target_link_libraries(GTest_run /Users/dmitrystarukhin/slae_course/ThreeDiagonalMatrix)
target_link_libraries(GTest_run gtest gtest_main)