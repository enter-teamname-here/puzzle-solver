#pragma once

#include <string>

namespace puzzlelib {
struct Cell {
  int x, y;
  Cell(int _x, int _y);
  Cell(std::string name);
};
}  // namespace puzzlelib
