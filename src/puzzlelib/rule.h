#pragma once
#include <string>

namespace puzzlelib {
class Rule {
 private:
  std::string type;
  std::string *cells;
};
}  // namespace puzzlelib
