#include "rule.h"

#include <stdexcept>

#include "cell.h"

namespace puzzlelib {
Rule::Rule(RuleType _type, std::vector<Cell> _cells, int _result)
    : type(_type), cells(_cells), result(_result) {}

Rule::Rule(RuleType _type, std::vector<Cell> _cells) : Rule(_type, _cells, -1) {
  if (_type == RuleType::kSum)
    throw std::invalid_argument("Rule of type kSum need result value");
}
}  // namespace puzzlelib
