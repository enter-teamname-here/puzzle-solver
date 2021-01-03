#include "puzzle.h"

namespace puzzlelib {
Puzzle::Puzzle(int _grid_width, int _grid_height)
    : grid_width(_grid_width), grid_height(_grid_height) {}

std::pair<int, int> Puzzle::GetGridDimension() {
  return {this->grid_width, this->grid_height};
}
}  // namespace puzzlelib
