#include "puzzle.h"

namespace puzzlelib {
Puzzle::Puzzle(int _grid_width, int _grid_height, std::vector<Rule> _rules,
               std::vector<int> _cell_contents)
    : grid_width(_grid_width),
      grid_height(_grid_height),
      rules(_rules),
      cell_contents(_cell_contents){};

Puzzle::Puzzle(int _grid_width, int _grid_height, std::vector<Rule> _rules)
    : Puzzle(_grid_width, _grid_height, {}, {}) {}

Puzzle::Puzzle(int _grid_width, int _grid_height)
    : Puzzle(_grid_width, _grid_height, {}) {}

std::pair<int, int> Puzzle::GetGridDimension() {
  return {this->grid_width, this->grid_height};
}
}  // namespace puzzlelib
