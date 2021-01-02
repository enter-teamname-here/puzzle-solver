#include "cell.h"

#include <cassert>
#include <stdexcept>

namespace puzzlelib {
Cell::Cell(int _x, int _y) : x(_x), y(_y), value_defined(false) {}

Cell::Cell(int _x, int _y, int _initial_value)
    : x(_x), y(_y), initial_value(_initial_value), value_defined(true) {}
}  // namespace puzzlelib
