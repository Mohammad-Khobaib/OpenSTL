#include <OpenSTL/vector.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

TEST(vector, constructor) {
  // Test case for default constructor
  {
    open_stl::vector<int> vec;
    ASSERT_EQ(vec.size(), 0);
    ASSERT_EQ(vec.capacity(), 0);
    ASSERT_EQ(vec.empty(), true);
  }

  // Test case for constructor with initializer list
  {
    open_stl::vector<int> vec = {1, 2, 3};
    ASSERT_EQ(vec.size(), 3);
    ASSERT_EQ(vec.capacity() >= 3, true);
    ASSERT_EQ(vec[0], 1);
  }

  // Test case for constructor with initializer list (using only one value)
  {
    open_stl::vector<int> vec = {42};
    ASSERT_EQ(vec.size(), 1);
    ASSERT_EQ(vec.capacity() >= 1, true);
    ASSERT_EQ(vec[0], 42);
  }

  // Test case for constructor with size argument
  {
    open_stl::vector<int> my_vector(5);
    ASSERT_EQ(my_vector.size(), 5);
    ASSERT_TRUE(my_vector.capacity() >= 5);
    for (size_t i = 0; i < my_vector.size(); ++i) {
      ASSERT_EQ(my_vector[i], 0);
    }
  }

  // Test case for constructor with size and value arguments
  {
    open_stl::vector<int> my_vector(5, 42);
    ASSERT_EQ(my_vector.size(), 5);
    ASSERT_EQ(my_vector.capacity() >= 5, true);
    for (size_t i = 0; i < my_vector.size(); ++i) {
      ASSERT_EQ(my_vector[i], 42);
    }
  }
}

TEST(vector, copy_constructor) {
  // Create a vector with some initial values
  open_stl::vector<int> original_vector = {1, 2, 3, 4, 5};

  // Create a new vector by copying the original vector
  open_stl::vector<int> copied_vector(original_vector);

  // Check if the size of the copied vector matches the original
  ASSERT_EQ(copied_vector.size(), original_vector.size());

  // Check if the capacity of the copied vector matches the original
  ASSERT_TRUE(copied_vector.capacity() >= original_vector.size());

  // // Check if the values of the copied vector match the original
  for (size_t i = 0; i < original_vector.size(); ++i) {
    ASSERT_EQ(copied_vector[i], original_vector[i]);
  }
}

TEST(vector, move_constructor) {
  // Create a vector with some initial values
  open_stl::vector<int> original_vector = {1, 2, 3, 4, 5};

  // Move construct a new vector from the original vector
  open_stl::vector<int> moved_vector(open_stl::move(original_vector));

  // Check if the size of the moved vector matches the original
  ASSERT_EQ(moved_vector.size(), 5);

  // Check if the capacity of the moved vector matches the original
  ASSERT_GE(moved_vector.capacity(), 5);

  // Check if the original vector has been moved (empty)
  ASSERT_EQ(original_vector.size(), 0);
  ASSERT_EQ(original_vector.capacity(), 0);
  ASSERT_EQ(original_vector.data(), nullptr);
}

TEST(vector, at) {
  // Test case for reference at(size_type off) function (non-const)
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Accessing elements within valid range
    for (size_t i = 0; i < my_vector.size(); ++i) {
      ASSERT_EQ(my_vector.at(i), i + 1);
    }

    // Accessing element out of range should throw out_of_range exception
    ASSERT_THROW(my_vector.at(my_vector.size()), std::out_of_range);

    // Accessing element with negative index should throw out_of_range exception
    ASSERT_THROW(my_vector.at(-1), std::out_of_range);
  }

  // Test case for const at() function
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Accessing elements within valid range
    for (size_t i = 0; i < my_const_vector.size(); ++i) {
      ASSERT_EQ(my_const_vector.at(i), i + 1);
    }

    // Accessing element out of range should throw out_of_range exception
    ASSERT_THROW(my_const_vector.at(my_const_vector.size()), std::out_of_range);

    // Accessing element with negative index should throw out_of_range exception
    ASSERT_THROW(my_const_vector.at(-1), std::out_of_range);
  }
}

TEST(vector, back) {
  // Test case for non-const back() function
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if the value returned by back() matches the last element of the
    // vector
    ASSERT_EQ(my_vector.back(), 5);
  }

  // Test case for const back() function
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if the value returned by back() matches the last element of the
    // vector
    ASSERT_EQ(my_const_vector.back(), 5);
  }
}

TEST(vector, begin) {
  // Test case for non-const begin() function
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if the iterator points to the first element of the vector
    ASSERT_EQ(*my_vector.begin(), 1);
  }

  // Test case for const begin() function
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if the const iterator points to the first element of the vector
    ASSERT_EQ(*my_const_vector.begin(), 1);
  }
}

TEST(vector, cbegin) {
  // Test case for cbegin() function
  const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

  // Check if the const iterator points to the first element of the vector
  ASSERT_EQ(*my_const_vector.cbegin(), 1);
}

TEST(vector, rbegin) {
  // Test case for non-const rbegin() function
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if the reverse iterator points to the last element of the vector
    ASSERT_EQ(*my_vector.rbegin(), 5);
  }

  // Test case for const rbegin() function
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if the const reverse iterator points to the last element of the
    // vector
    ASSERT_EQ(*my_const_vector.rbegin(), 5);
  }
}

TEST(vector, crbegin) {
  // Test case for crbegin() function
  const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

  // Check if the const reverse iterator points to the last element of the
  // vector
  ASSERT_EQ(*my_const_vector.crbegin(), 5);
}

TEST(vector, end) {
  // Test case for non-const end() function
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if the iterator points to the past-the-end element of the vector
    ASSERT_EQ(my_vector.end(), my_vector.data() + my_vector.size());
  }

  // Test case for const end() function
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if the const iterator points to the past-the-end element of the
    // vector
    ASSERT_EQ(my_const_vector.end(),
              my_const_vector.data() + my_const_vector.size());
  }
}

TEST(vector, cend) {
  // Test case for cend() function
  const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

  // Check if the const iterator points to the past-the-end element of the
  // vector
  ASSERT_EQ(my_const_vector.cend(),
            my_const_vector.data() + my_const_vector.size());
}

TEST(vector, rend) {
  // Test case for rend() function
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if the reverse iterator points to the element before the first
    // element of the vector
    ASSERT_EQ(my_vector.rend(),
              open_stl::vector<int>::reverse_iterator(&my_vector[0] - 1));
  }

  // Test case for const rend() function
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if the const reverse iterator points to the element before the
    // first element of the vector
    ASSERT_EQ(
        my_const_vector.rend(),
        open_stl::vector<int>::const_reverse_iterator(&my_const_vector[0] - 1));
  }
}

TEST(vector, crend) {
  // Test case for crend() function
  const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

  // Check if the const reverse iterator points to the element before the first
  // element of the vector
  ASSERT_EQ(
      my_const_vector.crend(),
      open_stl::vector<int>::const_reverse_iterator(&my_const_vector[0] - 1));
}

TEST(vector, data) {
  // Test case for data() function (non-const version)
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if the non-const data pointer points to the first element of the
    // vector
    ASSERT_EQ(my_vector.data(), &my_vector[0]);
  }

  // Test case for data() function (const version)
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if the const data pointer points to the first element of the vector
    ASSERT_EQ(my_const_vector.data(), &my_const_vector[0]);
  }
}

TEST(vector, front) {
  // Test case for front() function (non-const version)
  {
    open_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

    // Check if front() returns the correct reference to the first element of
    // the vector
    ASSERT_EQ(my_vector.front(), my_vector[0]);
  }

  // Test case for front() function (const version)
  {
    const open_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

    // Check if front() returns the correct const reference to the first element
    // of the vector
    ASSERT_EQ(my_const_vector.front(), my_const_vector[0]);
  }
}

TEST(vector, size) {
  // Test case 1: When vector is empty
  {
    open_stl::vector<int> empty_vector;
    ASSERT_EQ(empty_vector.size(), 0);
  }

  // Test case 2: When vector is partially filled
  {
    const size_t initial_size = 5;
    open_stl::vector<int> partially_filled_vector(initial_size);
    ASSERT_EQ(partially_filled_vector.size(), initial_size);
  }

  // Test case 3: When vector is fully filled
  {
    const size_t max_capacity = 100;  // Assuming a maximum capacity of 100
    open_stl::vector<int> fully_filled_vector(max_capacity);
    ASSERT_EQ(fully_filled_vector.size(), max_capacity);
  }
}

TEST(vector, capacity) {
  // Test case 1: When vector is empty
  {
    open_stl::vector<int> empty_vector;
    ASSERT_EQ(empty_vector.capacity(), 0);
  }

  // Test case 2: When vector is partially filled
  {
    const size_t initial_size = 5;
    open_stl::vector<int> partially_filled_vector(initial_size);
    ASSERT_EQ(partially_filled_vector.capacity(), initial_size);
  }

  // Test case 3: When vector is fully filled
  {
    const size_t max_capacity = 100;  // Assuming a maximum capacity of 100
    open_stl::vector<int> fully_filled_vector(max_capacity);
    ASSERT_EQ(fully_filled_vector.capacity(), max_capacity);
  }
}

TEST(vector, empty) {
  // Test case when vector is empty
  {
    open_stl::vector<int> empty_vector;
    ASSERT_TRUE(empty_vector.empty());
  }

  // Test case when vector is not empty
  {
    open_stl::vector<int> non_empty_vector = {1, 2, 3};
    ASSERT_FALSE(non_empty_vector.empty());
  }
}

TEST(vector, clear) {
  // Test case when vector is empty
  {
    open_stl::vector<int> empty_vector;
    empty_vector.clear();
    ASSERT_TRUE(empty_vector.empty());
  }

  // Test case when vector is not empty
  {
    open_stl::vector<int> non_empty_vector = {1, 2, 3};
    non_empty_vector.clear();
    ASSERT_TRUE(non_empty_vector.empty());
  }

  // Test case to check if size becomes 0 after clear
  {
    open_stl::vector<int> vector = {1, 2, 3};
    vector.clear();
    ASSERT_TRUE(vector.empty());
    ASSERT_EQ(vector.size(), 0);
  }
}

TEST(vector, reserve) {
  // Test case when count is less than current capacity
  {
    open_stl::vector<int> vector = {1, 2, 3};
    auto old_capacity = vector.capacity();
    vector.reserve(old_capacity - 1);
    ASSERT_EQ(vector.capacity(), old_capacity);
  }

  // Test case when count is greater than current capacity
  {
    open_stl::vector<int> vector = {1, 2, 3};
    auto old_capacity = vector.capacity();
    vector.reserve(old_capacity + 1);
    ASSERT_GT(vector.capacity(), old_capacity);
  }

  // Test case when count is equal to current capacity
  {
    open_stl::vector<int> vector = {1, 2, 3};
    auto old_capacity = vector.capacity();
    vector.reserve(old_capacity);
    ASSERT_EQ(vector.capacity(), old_capacity);
  }
}

TEST(vector, resize) {
  // Test case when new size is less than current size
  {
    open_stl::vector<int> vector = {1, 2, 3};
    vector.resize(2);
    ASSERT_EQ(vector.size(), 2);
    ASSERT_EQ(vector[0], 1);
    ASSERT_EQ(vector[1], 2);
  }

  // Test case when new size is greater than current size and less than capacity
  {
    open_stl::vector<int> vector = {1, 2, 3};
    vector.resize(5);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector[0], 1);
    ASSERT_EQ(vector[1], 2);
    ASSERT_EQ(vector[2], 3);
    ASSERT_EQ(vector[3], 0);  // Default initialized element
    ASSERT_EQ(vector[4], 0);  // Default initialized element
  }

  // Test case when new size is greater than current capacity
  {
    open_stl::vector<int> vector = {1, 2, 3};
    vector.resize(10);
    ASSERT_EQ(vector.size(), 10);
    ASSERT_EQ(vector[0], 1);
    ASSERT_EQ(vector[1], 2);
    ASSERT_EQ(vector[2], 3);
    ASSERT_EQ(vector[3], 0);  // Default initialized element
    ASSERT_EQ(vector[4], 0);  // Default initialized element
    // Additional assertions for other elements being default initialized
  }
}

TEST(vector, shrink_to_fit) {
  // Test case when capacity is greater than size
  {
    open_stl::vector<int> vector = {1, 2, 3};
    auto old_capacity = vector.capacity();
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), vector.size());
    ASSERT_EQ(vector.capacity(), old_capacity);
  }

  // Test case when capacity is equal to size
  {
    open_stl::vector<int> vector = {1, 2, 3};
    vector.reserve(10);  // Increase capacity
    auto old_capacity = vector.capacity();
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), vector.size());
    ASSERT_LT(vector.capacity(), old_capacity);
  }
}

TEST(vector, push_back) {
  // Test case for lvalue push_back()
  {
    open_stl::vector<int> vector = {1, 2, 3};
    vector.push_back(4);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.back(), 4);
  }

  // Test case for rvalue push_back()
  {
    open_stl::vector<std::string> vector;
    std::string str = "hello";
    vector.push_back(std::move(str));
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.back(), "hello");
    ASSERT_TRUE(str.empty());
  }
}

TEST(vector, pop_back) {
  open_stl::vector<int> vector = {1, 2, 3};
  vector.pop_back();
  ASSERT_EQ(vector.size(), 2);
  ASSERT_EQ(vector.back(), 2);
}

TEST(vector, emplace_back) {
  // Test case for emplacing an element with constructor arguments
  {
    open_stl::vector<std::string> vector;
    vector.emplace_back("hello");
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.back(), "hello");
  }
}

TEST(vector, emplace) {
  // Test case for emplacing into an empty vector
  {
    open_stl::vector<int> vector;
    auto it = vector.emplace(vector.begin(), 42);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(*it, 42);
  }

  // Test case for emplacing at the beginning of the vector
  {
    open_stl::vector<int> vector = {2, 3};
    auto it = vector.emplace(vector.begin(), 1);
    ASSERT_EQ(vector.size(), 3);
    ASSERT_EQ(*it, 1);
    ASSERT_EQ(vector.front(), 1);
  }

  // Test case for emplacing at the middle of the vector
  {
    open_stl::vector<int> vector = {1, 3};
    auto it = vector.emplace(vector.begin() + 1, 2);
    ASSERT_EQ(vector.size(), 3);
    ASSERT_EQ(*it, 2);
    ASSERT_EQ(vector[1], 2);
  }
}

TEST(vector, subscript_operator) {
  // Test case for accessing elements using operator[] in a non-const vector
  {
    open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    ASSERT_EQ(vector[0], 1);
    ASSERT_EQ(vector[2], 3);
    ASSERT_EQ(vector[4], 5);

    vector[1] = 10;
    ASSERT_EQ(vector[1], 10);
  }

  // Test case for accessing elements using operator[] in a const vector
  {
    const open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    ASSERT_EQ(vector[0], 1);
    ASSERT_EQ(vector[2], 3);
    ASSERT_EQ(vector[4], 5);

    // Attempting to modify elements in a const vector should fail to compile
    // vector[1] = 10; // Uncommenting this line should result in a compilation
    // error
  }
}

TEST(vector, erase) {
  // Test case for erasing an element at the beginning of the vector
  {
    open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    auto it = vector.erase(vector.begin());
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(*it, 2);
    ASSERT_EQ(vector.front(), 2);
  }

  // Test case for erasing an element in the middle of the vector
  {
    open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    auto it = vector.erase(vector.begin() + 2);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(*it, 4);
    ASSERT_EQ(vector[2], 4);
  }

  // Test case for erasing the last element of the vector
  {
    open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    auto it = vector.erase(vector.end() - 1);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(it, vector.end());
  }

  // Test case for erasing a range of elements from the vector
  {
    open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    auto it = vector.erase(vector.begin() + 1, vector.begin() + 3);
    ASSERT_EQ(vector.size(), 3);
    ASSERT_EQ(*it, 4);
    ASSERT_EQ(vector[1], 4);
  }

  // Test case for erasing all elements from the vector
  {
    open_stl::vector<int> vector = {1, 2, 3, 4, 5};
    auto it = vector.erase(vector.begin(), vector.end());
    ASSERT_TRUE(vector.empty());
    ASSERT_EQ(it, vector.end());
  }
}

TEST(vector, assignment_operator) {
  // Test case for assigning a vector to another vector
  {
    open_stl::vector<int> original = {1, 2, 3, 4, 5};
    open_stl::vector<int> assigned;
    assigned = original;

    ASSERT_EQ(assigned.size(), original.size());
    ASSERT_EQ(assigned.capacity(), original.capacity());

    for (size_t i = 0; i < original.size(); ++i) {
      ASSERT_EQ(assigned[i], original[i]);
    }
  }

  // Test case for move assigning a vector to another vector
  {
    open_stl::vector<int> original = {1, 2, 3, 4, 5};
    open_stl::vector<int> moved;
    moved = open_stl::move(original);

    ASSERT_EQ(moved.size(), 5);
    ASSERT_GE(moved.capacity(), 5);

    ASSERT_EQ(original.size(), 0);
    ASSERT_EQ(original.capacity(), 0);
    ASSERT_EQ(original.data(), nullptr);
  }
}

TEST(vector, equality_operator) {
  // Test case for comparing two equal vectors
  {
    open_stl::vector<int> vector1 = {1, 2, 3, 4, 5};
    open_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
    ASSERT_EQ(vector1, vector2);
  }

  // Test case for comparing two unequal vectors
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 4};
    ASSERT_NE(vector1, vector2);
  }

  // Test case for comparing vectors with different sizes
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
    ASSERT_NE(vector1, vector2);
  }
}

TEST(vector, inequality_operator) {
  // Test case for comparing two equal vectors
  {
    open_stl::vector<int> vector1 = {1, 2, 3, 4, 5};
    open_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
    ASSERT_FALSE(vector1 !=
                 vector2);  // Equal vectors should return false for operator!=
  }

  // Test case for comparing two unequal vectors
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 4};
    ASSERT_TRUE(vector1 !=
                vector2);  // Unequal vectors should return true for operator!=
  }

  // Test case for comparing vectors with different sizes
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
    ASSERT_TRUE(vector1 != vector2);  // Vectors with different sizes should
                                      // return true for operator!=
  }
}

TEST(vector, less_than_operator) {
  // Test case for comparing two vectors where the first is less than the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 4};
    ASSERT_TRUE(vector1 <
                vector2);  // First vector should be less than the second
  }

  // Test case for comparing two vectors where the first is greater than the
  // second
  {
    open_stl::vector<int> vector1 = {1, 2, 4};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_FALSE(vector1 <
                 vector2);  // First vector should not be less than the second
  }

  // Test case for comparing two vectors where the first is equal to the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_FALSE(
        vector1 <
        vector2);  // Equal vectors should not return true for operator<
  }
}

TEST(vector, greater_than_operator) {
  // Test case for comparing two vectors where the first is greater than the
  // second
  {
    open_stl::vector<int> vector1 = {1, 2, 4};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_TRUE(vector1 >
                vector2);  // First vector should be greater than the second
  }

  // Test case for comparing two vectors where the first is less than the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 4};
    ASSERT_FALSE(
        vector1 >
        vector2);  // First vector should not be greater than the second
  }

  // Test case for comparing two vectors where the first is equal to the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_FALSE(
        vector1 >
        vector2);  // Equal vectors should not return true for operator>
  }
}

TEST(vector, less_than_or_equal_operator) {
  // Test case for comparing two vectors where the first is less than the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 4};
    ASSERT_TRUE(
        vector1 <=
        vector2);  // First vector should be less than or equal to the second
  }

  // Test case for comparing two vectors where the first is greater than the
  // second
  {
    open_stl::vector<int> vector1 = {1, 2, 4};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_FALSE(vector1 <= vector2);  // First vector should not be less than
                                       // or equal to the second
  }

  // Test case for comparing two vectors where the first is equal to the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_TRUE(vector1 <=
                vector2);  // Equal vectors should return true for operator<=
  }
}

TEST(vector, greater_than_or_equal_operator) {
  // Test case for comparing two vectors where the first is greater than the
  // second
  {
    open_stl::vector<int> vector1 = {1, 2, 4};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_TRUE(
        vector1 >=
        vector2);  // First vector should be greater than or equal to the second
  }

  // Test case for comparing two vectors where the first is less than the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 4};
    ASSERT_FALSE(vector1 >= vector2);  // First vector should not be greater
                                       // than or equal to the second
  }

  // Test case for comparing two vectors where the first is equal to the second
  {
    open_stl::vector<int> vector1 = {1, 2, 3};
    open_stl::vector<int> vector2 = {1, 2, 3};
    ASSERT_TRUE(vector1 >=
                vector2);  // Equal vectors should return true for operator>=
  }
}

int main(int argc, char **argv) {
  // Initialize Google Test
  ::testing::InitGoogleTest(&argc, argv);

  // Run tests
  return RUN_ALL_TESTS();
}