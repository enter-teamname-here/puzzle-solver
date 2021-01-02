#pragma once

#include <string>

namespace puzzlelib {
struct Cell {
  int x, y, initial_value;
  bool value_defined;

  Cell(int _x, int _y);
  Cell(int _x, int _y, int _initial_value);
};
}  // namespace puzzlelib
