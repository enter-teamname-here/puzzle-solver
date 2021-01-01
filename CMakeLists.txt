cmake_minimum_required(VERSION 3.10)
project(puzzle_solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(PUZZLE_SOLVER_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PUZZLE_SOLVER_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(PUZZLE_SOLVER_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

set(PUZZLELIB_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/puzzlelib)

include_directories(${PROJECT_SOURCE_DIR}/deps/rapidjson/include)
include_directories(${PUZZLE_SOLVER_INSTALL_INCLUDE_DIR})
include_directories(${PUZZLELIB_HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)
