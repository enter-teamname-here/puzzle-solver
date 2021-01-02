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
  }
};

TEST_F(CellTest, Pos_0_0) { VerifyPosInit(0, 0); }
