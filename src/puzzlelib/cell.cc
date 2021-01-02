#include "cell.h"

#include <cassert>
#include <stdexcept>

namespace puzzlelib {
Cell::Cell(int _x, int _y) : x(_x), y(_y) {}

Cell::Cell(std::string name) {
  char first_letter = name[0];
  if ('a' <= first_letter && first_letter <= 'z') first_letter += ('A' - 'a');
  if (first_letter < 'A' || first_letter > 'Z')
    throw std::invalid_argument(
        "The first character of name should be an alphabet.");
  this->x = first_letter - 'A';
  std::string second_to_last = name.substr(1);
  this->y = std::stoi(second_to_last) - 1;
}
}  // namespace puzzlelib
