#pragma once

#include <utility>

#include "rule.h"

namespace puzzlelib {
class Puzzle {
 private:
  int grid_width;
  int grid_height;

 public:
  Puzzle(int grid_width, int grid_height);
  std::pair<int, int> GetGridDimension();
};
}  // namespace puzzlelib
