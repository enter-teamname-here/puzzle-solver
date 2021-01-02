cmake_minimum_required(VERSION 3.10)

add_subdirectory(puzzlelib)
set(SOURCE_FILES "main.cc")

add_executable(testbinary ${SOURCE_FILES})
target_link_libraries(testbinary puzzlelib)
install(TARGETS testbinary DESTINATION ${PUZZLE_SOLVER_INSTALL_BIN_DIR})
