cmake_minimum_required(VERSION 3.20)
project(slae_course)

file(GLOB_RECURSE files *.cpp)

foreach (file ${files})
    get_filename_component(ItName ${file} NAME_WE)
    add_executable(${ItName} ${file})
    target_link_libraries(${ItName} slae_course)
endforeach ()