cmake_minimum_required(VERSION 3.10)
project(puzzlelib C CXX)
set(SOURCE_FILES puzzle_def.h puzzle_def.cc rule.h rule.cc)
add_library(puzzlelib SHARED STATIC ${SOURCE_FILES})
