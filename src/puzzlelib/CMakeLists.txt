cmake_minimum_required(VERSION 3.10)
project(puzzlelib C CXX)

set(SOURCE_FILES "puzzle.h" "puzzle.cc" "rule.h" "rule.cc" "cell.h" "cell.cc")
add_library(puzzlelib SHARED STATIC ${SOURCE_FILES})

install(TARGETS puzzlelib DESTINATION ${PUZZLE_SOLVER_INSTALL_LIB_DIR})
install(FILES "puzzle_def.h" "rule.h" DESTINATION ${PUZZLE_SOLVER_INSTALL_INCLUDE_DIR})
