#include "puzzle_def.h"

namespace puzzlelib {
Puzzle::Puzzle(int grid_width, int grid_height) {
  this->grid_width = grid_width;
  this->grid_height = grid_height;
}

std::pair<int, int> Puzzle::grid_dimension() {
  return {this->grid_width, this->grid_height};
}
}  // namespace puzzlelib
