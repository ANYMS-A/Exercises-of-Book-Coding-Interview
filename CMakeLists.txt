cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(coding_interview LANGUAGES CXX)


file(GLOB exefiles "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(mainfile IN LISTS exefiles)
    message(STATUS "add source file: " ${mainfile} " into exe file.")
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
endforeach()


