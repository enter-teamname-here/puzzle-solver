#pragma once

#include <string>
#include <utility>

namespace puzzlelib {
struct Cell {
  int x, y, initial_value;
  bool value_defined;

  Cell(int _x, int _y);
  Cell(int _x, int _y, int _initial_value);
  std::pair<int, int> GetCellPosition();
};

bool operator==(const Cell& lhs, const Cell& rhs);
}  // namespace puzzlelib
