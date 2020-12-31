cmake_minimum_required(VERSION 3.10)
set(SOURCE_FILES main.cc)
add_subdirectory(puzzlelib)
add_executable(testbinary ${SOURCE_FILES})
