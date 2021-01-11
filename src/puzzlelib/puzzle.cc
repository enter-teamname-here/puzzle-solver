#include "puzzle.h"

#include <algorithm>
#include <map>

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

  std::vector<Cell> cellpos_table;
  std::map<Cell, int> cellpos_revref;
  for (auto& rule : this->rules) {
    // TODO: Implement "sum" rule type
    if (rule.type == RuleType::kSum) continue;
    for (auto& cell : rule.cells) {
      auto pos = cell.GetCellPosition();
      if (cellpos_revref.count(cell) != 0) continue;
      cellpos_table.push_back(cell);
      cellpos_revref[cell] = cellpos_table.size() - 1;
    }
  }

  std::vector<Node*> headers;
  Node* prev_col = root;
  for (int i = 0; i < cellpos_table.size(); ++i) {
    Node* col = new Node();
    col->left = prev_col;
    prev_col->right = col;
    col->up = col;
    col->down = col;
    col->size = 0;
    headers.push_back(col);
    prev_col = col;
  }
  for (auto& rule : this->rules) {
    for (int i = 0; i < this->cell_contents.size(); ++i) {
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

  for (int i = 0; i < cellpos_table.size(); ++i) {
    for (int j = 0; j < this->cell_contents.size(); ++j) {
      auto cell = cellpos_table[i];
      Node* last = headers[i]->up;
      Node* row = new Node();
      row->up = last;
      last->down = row;
      row->down = headers[i];
      headers[i]->up = row;
      row->column_top = headers[i];
      headers[i]->size++;
      Node* prev_row = row;
      int offset = this->cell_contents.size();
      for (auto& rule : this->rules) {
        // TODO: Implement "sum" rule type
        if (rule.type == RuleType::kSum) continue;
        int current_offset = offset;
        offset += this->cell_contents.size();
        auto find_result =
            std::find(rule.cells.begin(), rule.cells.end(), cell);
        if (find_result == rule.cells.end()) continue;
        int idx =
            current_offset + std::distance(rule.cells.begin(), find_result);
        last = headers[idx]->up;
        Node* row = new Node();
        row->up = last;
        last->down = row;
        row->down = headers[idx];
        headers[idx]->up = row;
        prev_row->right = row;
        row->left = prev_row;
        row->column_top = headers[idx];
        headers[idx]->size++;
        prev_row = row;
      }
      prev_row->right = row;
      row->left = prev_row;
    }
  }

  return {root, headers};
}
}  // namespace puzzlelib
