#include <cell.h>
#include <gtest/gtest.h>
#include <puzzle_def.h>

#include <stdexcept>
#include <string>
#include <utility>

using puzzlelib::Cell;
using puzzlelib::Puzzle;
using std::make_pair;

class PuzzleTest : public ::testing::Test {
 protected:
  virtual void VerifyDim(int grid_width, int grid_height) {
    Puzzle puzzle(grid_width, grid_height);
    ASSERT_EQ(puzzle.GetGridDimension(), make_pair(grid_width, grid_height));
  }
};

TEST_F(PuzzleTest, 9_by_9) { VerifyDim(9, 9); }

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
