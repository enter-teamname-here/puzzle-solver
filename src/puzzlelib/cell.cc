#include "cell.h"

#include <stdexcept>
#include <tuple>

namespace puzzlelib {
Cell::Cell(int _x, int _y)
    : x(_x), y(_y), initial_value(-1), value_defined(false) {}

Cell::Cell(int _x, int _y, int _initial_value)
    : x(_x), y(_y), initial_value(_initial_value), value_defined(true) {}

bool operator==(const Cell& lhs, const Cell& rhs) {
  if (lhs.value_defined != rhs.value_defined) return false;
  if (lhs.value_defined)
    return lhs.x == rhs.x && lhs.y == rhs.y &&
           lhs.initial_value == rhs.initial_value;
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator<(const Cell& lhs, const Cell& rhs) {
  std::tuple<int, int, int, int> lhs_tuple = {lhs.x, lhs.y, lhs.initial_value,
                                              lhs.value_defined};
  std::tuple<int, int, int, int> rhs_tuple = {rhs.x, rhs.y, rhs.initial_value,
                                              rhs.value_defined};
  return lhs_tuple < rhs_tuple;
}

std::pair<int, int> Cell::GetCellPosition() const { return {this->x, this->y}; }
}  // namespace puzzlelib
