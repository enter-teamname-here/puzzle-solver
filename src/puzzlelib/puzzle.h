#pragma once

#include <utility>
#include <vector>

#include "node.h"
#include "rule.h"

namespace puzzlelib {
class Puzzle {
 private:
  int grid_width;
  int grid_height;
  std::vector<Rule> rules;
  std::vector<int> cell_contents;

 public:
  Puzzle(int _grid_width, int _grid_height, std::vector<Rule> _rules,
         std::vector<int> _cell_contents);
  std::pair<int, int> GetGridDimension();
  std::pair<Node*, std::vector<Node*>> GenerateKnuthMatrix() const;
};
}  // namespace puzzlelib
