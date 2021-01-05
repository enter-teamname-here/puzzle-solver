#include <cell.h>
#include <gtest/gtest.h>
#include <node.h>
#include <puzzle.h>
#include <rule.h>

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using puzzlelib::Cell;
using puzzlelib::Node;
using puzzlelib::Puzzle;
using puzzlelib::Rule;
using puzzlelib::RuleType;
using std::make_pair;

class PuzzleTest : public ::testing::Test {
 protected:
  virtual void VerifyDim(int grid_width, int grid_height) {
    Puzzle puzzle(grid_width, grid_height, {}, {});
    ASSERT_EQ(puzzle.GetGridDimension(), make_pair(grid_width, grid_height));
  }

  virtual void VerifyKnuthMatrixHeaders(const Puzzle& puzzle) {
    auto [matrix, headers] = puzzle.GenerateKnuthMatrix();
    Node* current = matrix->right;
    int idx = 0;
    while (current != matrix) {
      EXPECT_EQ(current, headers[idx]);
      idx++;
      current = current->right;
    }
  }
};

TEST_F(PuzzleTest, 9_by_9) { VerifyDim(9, 9); }

TEST_F(PuzzleTest, HeaderGeneratesCorrectly) {
  Cell cell1(0, 0, 1);
  Cell cell2(1, 0);
  Rule rule(RuleType::kExclusive, {cell1, cell2});
  Puzzle puzzle(2, 1, {rule}, {1, 2});
  VerifyKnuthMatrixHeaders(puzzle);
}

class CellTest : public ::testing::Test {
 protected:
  virtual void VerifyPosInit(int x, int y) {
    Cell cell(x, y);
    ASSERT_EQ(cell.x, x);
    ASSERT_EQ(cell.y, y);
    ASSERT_EQ(cell.value_defined, false);
  }

  virtual void VerifyPosInitWithInitVal(int x, int y, int initial_value) {
    Cell cell(x, y, initial_value);
    ASSERT_EQ(cell.x, x);
    ASSERT_EQ(cell.y, y);
    ASSERT_EQ(cell.initial_value, initial_value);
    ASSERT_EQ(cell.value_defined, true);
  }

  virtual void VerifyEquality(const Cell& cell1, const Cell& cell2,
                              bool expected) {
    ASSERT_EQ(cell1 == cell2, expected);
  }
};

TEST_F(CellTest, Pos_0_0) { VerifyPosInit(0, 0); }

TEST_F(CellTest, Pos_0_0_InitVal_42) { VerifyPosInitWithInitVal(0, 0, 42); }

TEST_F(CellTest, Pos_0_0_Equality) {
  Cell cell1(0, 0);
  Cell cell2(0, 0);
  VerifyEquality(cell1, cell2, true);
}

TEST_F(CellTest, Pos_0_0_0_1_Mismatch) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  VerifyEquality(cell1, cell2, false);
}

TEST_F(CellTest, Pos_0_0_42_Equality) {
  Cell cell1(0, 0, 42);
  Cell cell2(0, 0, 42);
  VerifyEquality(cell1, cell2, true);
}

TEST_F(CellTest, Pos_0_0_42_0_0_0_Mismatch) {
  Cell cell1(0, 0, 42);
  Cell cell2(0, 0, 0);
  VerifyEquality(cell1, cell2, false);
}

TEST_F(CellTest, InitVal_Mismatch) {
  Cell cell1(0, 0);
  Cell cell2(0, 0, 42);
  VerifyEquality(cell1, cell2, false);
}

class RuleTest : public ::testing::Test {
 protected:
  virtual void VerifyInit(RuleType type, std::vector<Cell> cells) {
    Rule rule(type, cells);
    ASSERT_EQ(rule.type, type);
    ASSERT_EQ(rule.cells, cells);
  }

  virtual void VerifyInitWithResult(RuleType type, std::vector<Cell> cells,
                                    int result) {
    Rule rule(type, cells, result);
    ASSERT_EQ(rule.type, type);
    ASSERT_EQ(rule.cells, cells);
    ASSERT_EQ(rule.result, result);
  }

  virtual void VerifyEquality(const Rule& rule1, const Rule& rule2,
                              bool expected) {
    ASSERT_EQ(rule1 == rule2, expected);
  }
};

TEST_F(RuleTest, ExeclusiveInit) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  Cell cell3(1, 0);
  VerifyInit(RuleType::kExclusive, {cell1, cell2, cell3});
}

TEST_F(RuleTest, ValidSumInit) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  Cell cell3(1, 0);
  VerifyInitWithResult(RuleType::kSum, {cell1, cell2, cell3}, 42);
}

TEST_F(RuleTest, InvalidSumInit) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  Cell cell3(1, 0);
  try {
    VerifyInit(RuleType::kSum, {cell1, cell2, cell3});
    FAIL() << "Expected exception";
  } catch (const std::invalid_argument& err) {
    SUCCEED();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST_F(RuleTest, ExclusiveEquality) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  Rule rule1(RuleType::kExclusive, {cell1, cell2});
  Rule rule2(RuleType::kExclusive, {cell1, cell2});
  VerifyEquality(rule1, rule2, true);
  Rule rule3(RuleType::kExclusive, {cell1});
  VerifyEquality(rule1, rule3, false);
}

TEST_F(RuleTest, SumEquality) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  Rule rule1(RuleType::kSum, {cell1, cell2}, 42);
  Rule rule2(RuleType::kSum, {cell1, cell2}, 42);
  VerifyEquality(rule1, rule2, true);
  Rule rule3(RuleType::kSum, {cell1, cell2}, 0);
  VerifyEquality(rule1, rule3, false);
  Rule rule4(RuleType::kSum, {cell1}, 42);
  VerifyEquality(rule1, rule4, false);
}

TEST_F(RuleTest, ExeclusiveSumMismatch) {
  Cell cell1(0, 0);
  Cell cell2(0, 1);
  Rule rule1(RuleType::kSum, {cell1, cell2}, 42);
  Rule rule2(RuleType::kExclusive, {cell1, cell2});
  VerifyEquality(rule1, rule2, false);
}
