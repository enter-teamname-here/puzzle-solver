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

std::pair<Node*, std::vector<Node*>> Puzzle::GenerateKnuthMatrix() const {
  Node* root = new Node();
  root->up = root;
  root->down = root;

  std::vector<Node*> headers;
  Node* prev_col = root;
  for (int y = 0; y < grid_height; ++y) {
    for (int x = 0; x < grid_width; ++x) {
      Node* col = new Node();
      col->left = prev_col;
      prev_col->right = col;
      col->up = col;
      col->down = col;
      col->size = 0;
      headers.push_back(col);
      prev_col = col;
    }
  }

  root->left = prev_col;
  prev_col->right = root;
  return {root, headers};
}
}  // namespace puzzlelib
