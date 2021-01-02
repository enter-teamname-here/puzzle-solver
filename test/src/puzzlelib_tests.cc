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
  virtual void VerifyNameInit(std::string name, int expected_x,
                              int expected_y) {
    Cell cell(name);
    ASSERT_EQ(cell.x, expected_x);
    ASSERT_EQ(cell.y, expected_y);
  }
};

TEST_F(CellTest, UppercaseName) { VerifyNameInit("A1", 0, 0); }

TEST_F(CellTest, LowercaseName) { VerifyNameInit("a1", 0, 0); }

TEST_F(CellTest, NonAlphabetFirstCase) {
  try {
    VerifyNameInit("42", 0, 0);
    FAIL() << "Expected Cell() to throw exception";
  } catch (std::invalid_argument const &err) {
    SUCCEED();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST_F(CellTest, NonNumericIndex) {
  try {
    VerifyNameInit("AA", 0, 0);
    FAIL() << "Expected Cell() to throw exception";
  } catch (std::invalid_argument const &err) {
    SUCCEED();
  } catch (...) {
    FAIL() << "Expected std::invalid_argument";
  }
}
