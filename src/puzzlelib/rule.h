#pragma once
#include <string>
#include <vector>

#include "cell.h"

namespace puzzlelib {
enum class RuleType { kExclusive, kSum };

struct Rule {
  RuleType type;
  std::vector<Cell> cells;
  int result;
  Rule(RuleType _type, std::vector<Cell> _cells);
  Rule(RuleType _type, std::vector<Cell> _cells, int _result);
};

bool operator==(const Rule& lhs, const Rule& rhs);
}  // namespace puzzlelib
