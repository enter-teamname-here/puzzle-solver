#pragma once

#include <rapidjson/document.h>

#include <string>

#include "puzzle.h"
#include "rule.h"

namespace puzzlelib {
class PuzzleParser {
 public:
  static Puzzle ParsePuzzleJSON(std::string json);
};
}  // namespace puzzlelib
