cmake_minimum_required(VERSION 3.10)
project(puzzle_solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
include_directories(deps/rapidjson/include)
add_subdirectory(src)
