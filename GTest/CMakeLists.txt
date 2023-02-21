project(Gtest)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB tests *.cpp)

foreach(item ${tests})
    get_filename_component(ItName ${item} NAME_WE)
    add_executable("${ItName}" ${item})
    add_test(NAME "${ItName}" COMMAND ${item})
    target_link_libraries(${ItName} slae_course gtest gtest_main)
endforeach()