#include <memory>

struct Node {
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  std::shared_ptr<Node> up;
  std::shared_ptr<Node> down;
  std::shared_ptr<Node> column_top;
  int size;
};
