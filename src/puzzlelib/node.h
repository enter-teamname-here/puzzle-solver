#pragma once

namespace puzzlelib {
struct Node {
  Node* left;
  Node* right;
  Node* up;
  Node* down;
  Node* column_top;
  int size;
};
}  // namespace puzzlelib
