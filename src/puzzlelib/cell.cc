#include "cell.h"

#include <cassert>
#include <stdexcept>

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
}  // namespace puzzlelib
