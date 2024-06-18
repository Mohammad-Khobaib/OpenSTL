#include <OpenSTL/memory.h>
#include <gtest/gtest.h>

// Define a test case for allocator's allocate function
TEST(allocator, allocate) {
  // Create an instance of open_stl::allocator<int>
  open_stl::allocator<int> open_stl_allocator;

  // Allocate memory for 4 integers
  int *x = open_stl_allocator.allocate(4);

  // Check if allocation was successful
  ASSERT_NE(x, nullptr);

  // Initialize the allocated memory
  for (int i = 0; i < 4; ++i) {
    x[i] = i + 1;  // Assign values 1, 2, 3, 4 to the allocated memory
  }

  // Verify the values assigned
  for (int i = 0; i < 4; ++i) {
    ASSERT_EQ(x[i], i + 1);
  }

  // Deallocate the allocated memory
  open_stl_allocator.deallocate(x);
}

int main(int argc, char **argv) {
  // Initialize Google Test
  ::testing::InitGoogleTest(&argc, argv);

  // Run tests
  return RUN_ALL_TESTS();
}
