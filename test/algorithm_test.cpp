#include <OpenSTL/algorithm.h>
#include <gtest/gtest.h>

TEST(lexicographical_compare, EqualRanges) {
  int lhs[] = {1, 2, 3};
  int rhs[] = {1, 2, 3};
  EXPECT_EQ(open_stl::lexicographical_compare(lhs, lhs + 3, rhs, rhs + 3),
            false);
}

int main(int argc, char **argv) {
  // Initialize Google Test
  ::testing::InitGoogleTest(&argc, argv);

  // Run tests
  return RUN_ALL_TESTS();
}
