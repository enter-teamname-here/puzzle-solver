#pragma once

#include <string>

namespace puzzlelib {
struct Cell {
  int x, y;
  Cell(std::string name);
};
}  // namespace puzzlelib
