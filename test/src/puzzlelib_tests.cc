#include <gtest/gtest.h>
#include <puzzle_def.h>

#include <utility>

using puzzlelib::Puzzle;
using std::make_pair;

class PuzzleTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
  virtual void verify_dim(int grid_width, int grid_height) {
    Puzzle puzzle(grid_width, grid_height);
    ASSERT_EQ(puzzle.GetGridDimension(), make_pair(grid_width, grid_height));
  }
};

TEST_F(PuzzleTest, 9_by_9) { verify_dim(9, 9); }
