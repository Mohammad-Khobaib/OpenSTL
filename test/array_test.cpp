#include <OpenSTL/array.h>
#include <gtest/gtest.h>

#include <type_traits>

TEST(array, constructor) {
  {
    open_stl::array<int, 5> arr;
    for (int i = 0; i < 5; i++) {
      EXPECT_EQ(arr[i], 0);
    }
  }
  {
    const open_stl::array<int, 5> arr;
    for (int i = 0; i < 5; i++) {
      EXPECT_EQ(arr[i], 0);
    }
  }
  {
    open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
      EXPECT_EQ(arr[i], i + 1);
    }
  }
  {
    const open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
      EXPECT_EQ(arr[i], i + 1);
    }
  }
}

TEST(array, at) {
  open_stl::array<int, 3> array = {10, 20, 30};

  EXPECT_EQ(array.at(0), 10);
  EXPECT_EQ(array.at(1), 20);
  EXPECT_EQ(array.at(2), 30);

  EXPECT_THROW(array.at(3), std::out_of_range);
}

TEST(array, subscript_operator) {
  open_stl::array<int, 3> array = {10, 20, 30};

  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);
  EXPECT_EQ(array[2], 30);

  array[0] = 100;
  array[1] = 200;
  array[2] = 300;
  EXPECT_EQ(array[0], 100);
  EXPECT_EQ(array[1], 200);
  EXPECT_EQ(array[2], 300);
}

TEST(array, fill) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  arr.fill(0);
  for (const auto &val : arr) {
    EXPECT_EQ(val, 0);
  }
}

TEST(array, back) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.back(), 5);
}

TEST(array, front) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.front(), 1);
}

TEST(array, begin) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(*arr.begin(), 1);
}

TEST(array, cbegin) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(*arr.cbegin(), 1);
}

TEST(array, crbegin) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(*arr.crbegin(), 5);
}

TEST(array, cend) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto end = arr.cend();
  EXPECT_EQ(*(--end), 5);
}

TEST(array, crend) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto end = arr.crend();
  EXPECT_EQ(*(--end), 1);
}

TEST(array, data) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(*arr.data(), 1);
}

TEST(array, end) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto end = arr.end();
  EXPECT_EQ(*(--end), 5);
}

TEST(array, empty) {
  {
    open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(arr.empty(), false);
  }
  {
    open_stl::array<int, 0> arr;
    EXPECT_EQ(arr.empty(), true);
  }
}

TEST(array, max_size) {
  {
    open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(arr.max_size(), 5);
  }
  {
    open_stl::array<int, 0> arr;
    EXPECT_EQ(arr.max_size(), 0);
  }
}

TEST(array, rbegin) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(*arr.rbegin(), 5);
}

TEST(array, rend) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.rend();
  EXPECT_EQ(*(--it), 1);
}

TEST(array, size) {
  open_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
}

TEST(array, swap) {
  open_stl::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  open_stl::array<int, 5> arr2 = {5, 4, 3, 2, 1};
  arr1.swap(arr2);
  EXPECT_EQ(arr1.front(), 5);
}

TEST(array, assighnment_operator) {
  open_stl::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  open_stl::array<int, 5> arr2 = {5, 4, 3, 2, 1};
  arr1 = arr2;
  EXPECT_EQ(arr1.front(), 5);
}

int main(int argc, char **argv) {
  // Initialize Google Test
  ::testing::InitGoogleTest(&argc, argv);

  // Run tests
  return RUN_ALL_TESTS();
}
