cmake_minimum_required(VERSION 3.10)
project(puzzle_solver_tests)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(deps/googletest)
include_directories(deps/googletest/googletest/include)
include_directories(${PUZZLELIB_HEADERS_DIR})

set(SOURCE_FILES "main.cc" "src/puzzlelib_tests.cc")
add_executable(run_tests ${SOURCE_FILES})
target_link_libraries(run_tests puzzlelib gtest)
install(TARGETS run_tests DESTINATION bin)
