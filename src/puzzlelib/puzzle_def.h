#ifndef PUZZLE_DEF_H
#define PUZZLE_DEF_H

#include <utility>

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

#endif
