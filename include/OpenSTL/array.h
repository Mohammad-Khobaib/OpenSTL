#ifndef OPEN_STL_ARRAY_
#define OPEN_STL_ARRAY_

#include <OpenSTL/algorithm.h>
#include <OpenSTL/internal/reverse_iterator.h>
#include <OpenSTL/utility.h>
#include <stddef.h>

#include <exception>
#include <initializer_list>

namespace open_stl {
template <typename T, std::size_t N> struct array {
  using value_type = T;
  using const_iterator = const value_type *;
  using const_pointer = const value_type *;
  using const_reference = const value_type &;
  using const_reverse_iterator = internal::reverse_iterator<const_iterator>;
  using difference_type = std::ptrdiff_t;
  using iterator = value_type *;
  using pointer = value_type *;
  using reference = value_type &;
  using reverse_iterator = internal::reverse_iterator<iterator>;
  using size_type = std::size_t;

  /*
      Accesses the element at the specified position with bounds checking.

      Template Parameters:
          - None.

      Parameters:
          - off: The index of the element to access.

      Returns:
          - A reference to the element at the specified index.

      Throws:
          - std::out_of_range: If the index is out of the valid range [0, N).

      This function provides access to the element at the specified index `off`.
      It checks if the index is within the valid range [0, N). If the index is
      out of range, it throws an `std::out_of_range` exception with an
     appropriate error message.
  */
  reference at(size_type off) {
    if (off < 0 || off >= N) {
      throw std::out_of_range(
          "Error: Array index out of range. Please ensure the index is within "
          "the valid range.");
    }
    return m_data[off];
  }

  /*
      Accesses the element at the specified position with bounds checking (const
     version).

      Template Parameters:
          - None.

      Parameters:
          - off: The index of the element to access.

      Returns:
          - A const reference to the element at the specified index.

      Throws:
          - std::out_of_range: If the index is out of the valid range [0, N).

      This function provides read-only access to the element at the specified
     index `off`. It checks if the index is within the valid range [0, N). If
     the index is out of range, it throws an `std::out_of_range` exception with
     an appropriate error message.
  */
  const_reference at(size_type off) const {
    if (off < 0 || off >= N) {
      throw std::out_of_range(
          "Error: Array index out of range. Please ensure the index is within "
          "the valid range.");
    }
    return m_data[off];
  }

  /*
      Accesses the last element in the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A reference to the last element in the array.

      This function provides access to the last element of the array. It assumes
      that the array is not empty, so it does not perform any bounds checking.
  */
  reference back() { return m_data[N - 1]; }

  /*
      Accesses the last element in the array (const version).

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const reference to the last element in the array.

      This function provides read-only access to the last element of the array.
      It assumes that the array is not empty, so it does not perform any bounds
     checking.
  */
  const_reference back() const { return m_data[N - 1]; }

  /*
    Returns an iterator to the beginning of the array.

    Template Parameters:
        - None.

    Parameters:
        - None.

    Returns:
        - An iterator pointing to the first element in the array.

    This function provides an iterator that points to the beginning of the
    array. It can be used to iterate over the elements of the array.
  */
  iterator begin() { return &m_data[0]; }

  /*
      Returns a const iterator to the beginning of the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const iterator pointing to the first element in the array.

      This function provides a const iterator that points to the beginning of
     the array. It can be used to iterate over the elements of the array in a
     read-only manner.
  */
  const_iterator begin() const { return &m_data[0]; }

  /*
      Returns a const iterator to the beginning of the array
      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const iterator pointing to the first element in the array.

      This function provides a const iterator that points to the beginning of
     the array. It can be used to iterate over the elements of the array in a
     read-only manner.
  */
  const_iterator cbegin() const { return &m_data[0]; }

  /*
      Returns a const reverse iterator to the beginning of the reversed array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const reverse iterator pointing to the last element in the array.

      This function provides a const reverse iterator that points to the last
     element of the array, allowing iteration over the elements of the array in
     reverse order in a read-only manner.
  */
  const_reverse_iterator crbegin() const {
    return const_reverse_iterator(&m_data[N - 1]);
  }

  /*
      Returns a const iterator to the end of the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const iterator pointing to the element after the last element in
     the array.

      This function provides a const iterator that points to the position after
     the last element in the array. It can be used to determine the end of the
     array when iterating over its elements in a read-only manner.
  */
  const_iterator cend() const { return &m_data[N]; }

  /*
      Returns a const reverse iterator to the end of the reversed array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const reverse iterator pointing to the position before the first
     element in the array.

      This function provides a const reverse iterator that points to the
     position before the first element in the array. It can be used to determine
     the end of the array when iterating over its elements in reverse order in a
     read-only manner.
  */
  const_reverse_iterator crend() const {
    return const_reverse_iterator(&m_data[-1]);
  }

  /*
      Returns a pointer to the underlying data.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A pointer to the first element in the array.

      This function returns a pointer to the first element in the array,
     providing direct access to the underlying data of the array.
  */
  pointer data() { return &m_data[0]; }

  /*
      Returns a const pointer to the underlying data (const version).

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const pointer to the first element in the array.

      This function returns a const pointer to the first element in the array,
      providing read-only access to the underlying data of the array.
  */
  const_pointer data() const { return &m_data[0]; }

  /*
      Returns an iterator to the end of the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - An iterator pointing to the element after the last element in the
     array.

      This function returns an iterator that points to the position after the
     last element in the array. It can be used to determine the end of the array
     when iterating over its elements.
  */
  iterator end() { return &m_data[N]; }

  /*
      Returns a const iterator to the end of the array (const version).

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const iterator pointing to the element after the last element in
     the array.

      This function returns a const iterator that points to the position after
     the last element in the array. It can be used to determine the end of the
     array when iterating over its elements in a read-only manner.
  */
  const_iterator end() const { return &m_data[N]; }

  /*
      Checks if the array is empty.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - True if the array is empty, false otherwise.

      This function returns true if the array is empty (i.e., if its size is
     zero), and false otherwise. It is constexpr, allowing its evaluation at
     compile time.
  */
  bool empty() const { return N == 0; }

  /*
      Returns a reference to the first element in the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A reference to the first element in the array.

      This function returns a reference to the first element in the array,
      allowing direct access to modify or read the element.
  */
  reference front() { return m_data[0]; }

  /*
      Returns a const reference to the first element in the array (const
     version).

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const reference to the first element in the array.

      This function returns a const reference to the first element in the array,
      allowing read-only access to the element. It is constexpr, allowing its
      evaluation at compile time.
  */
  const_reference front() const { return m_data[0]; }

  /*
      Returns the maximum possible size of the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - The maximum possible size of the array.

      This function returns the maximum possible size of the array, which is
      determined by the template parameter N. It is constexpr, allowing its
      evaluation at compile time.
  */
  size_type max_size() const { return N; }

  /*
      Returns a reverse iterator to the beginning of the reversed array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A reverse iterator pointing to the last element in the array.

      This function returns a reverse iterator that points to the last element
      of the array, allowing iteration over the elements of the array in reverse
     order.
  */
  reverse_iterator rbegin() { return reverse_iterator(&m_data[N - 1]); }

  /*
      Returns a const reverse iterator to the beginning of the reversed array
     (const version).

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const reverse iterator pointing to the last element in the array.

      This function returns a const reverse iterator that points to the last
     element of the array, allowing iteration over the elements of the array in
     reverse order in a read-only manner.
  */
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(&m_data[N - 1]);
  }

  /*
      Returns a reverse iterator to the end of the reversed array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A reverse iterator pointing to the position before the first element
     in the array.

      This function returns a reverse iterator that points to the position
     before the first element in the array, allowing iteration over the elements
     of the array in reverse order.
  */
  reverse_iterator rend() { return reverse_iterator(&m_data[-1]); }

  /*
      Returns a const reverse iterator to the end of the reversed array (const
     version).

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - A const reverse iterator pointing to the position before the first
     element in the array.

      This function returns a const reverse iterator that points to the position
     before the first element in the array, allowing iteration over the elements
     of the array in reverse order in a read-only manner.
  */
  const_reverse_iterator rend() const {
    return const_reverse_iterator(&m_data[-1]);
  }

  /*
      Returns the size of the array.

      Template Parameters:
          - None.

      Parameters:
          - None.

      Returns:
          - The size of the array.

      This function returns the size of the array, which is determined by the
      template parameter N. It is constexpr, allowing its evaluation at compile
     time.
  */
  size_type size() const { return N; }

  /*
      Fills the array with the specified value.

      Template Parameters:
          - None.

      Parameters:
          - val: The value to fill the array with.

      Returns:
          - None.

      This function assigns the specified value `val` to each element of the
     array.
  */
  void fill(const_reference val) {
    for (size_type i = 0; i < N; i++) {
      m_data[i] = val;
    }
  }

  /*
      Swaps the contents of this array with another array.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to swap with.

      Returns:
          - None.

      This function swaps the contents of this array with another array `right`.
      Each element of this array is swapped with the corresponding element of
     `right`.
  */
  void swap(array<T, N> &right) {
    for (size_type i = 0; i < N; i++) {
      open_stl::swap(m_data[i], right.m_data[i]);
    }
  }

  /*
      Accesses the element at the specified position without bounds checking.

      Template Parameters:
          - None.

      Parameters:
          - off: The index of the element to access.

      Returns:
          - A reference to the element at the specified index.

      Note:
          - No bounds checking is performed. It is the caller's responsibility
     to ensure that the index is within the valid range.

      This function provides direct access to the element at the specified index
     `off`. No bounds checking is performed, so the caller must ensure that the
     index is within the valid range.
  */
  reference operator[](size_type off) { return m_data[off]; }

  /*
      Accesses the element at the specified position without bounds checking
     (const version).

      Template Parameters:
          - None.

      Parameters:
          - off: The index of the element to access.

      Returns:
          - A const reference to the element at the specified index.

      Note:
          - No bounds checking is performed. It is the caller's responsibility
     to ensure that the index is within the valid range.

      This function provides read-only access to the element at the specified
     index `off`. No bounds checking is performed, so the caller must ensure
     that the index is within the valid range.
  */
  const_reference operator[](size_type off) const { return m_data[off]; }

  /*
      Assignment operator for assigning one array to another.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to assign from.

      Returns:
          - A reference to the current array after assignment.

      Note:
          - Checks for self-assignment are performed to prevent unnecessary
     work.

      This assignment operator copies each element from the array `right` to
      the corresponding position in the current array.
  */
  array<T, N> &operator=(const array<T, N> &right) {
    if (this != &right) {
      for (size_type i = 0; i < N; i++) {
        m_data[i] = right.m_data[i];
      }
    }
    return *this;
  }

  /*
      Move assignment operator for moving the contents of one array to another.

      Template Parameters:
          - None.

      Parameters:
          - right: The rvalue reference to another array object.

      Returns:
          - A reference to the current array after move assignment.

      This move assignment operator moves each element from the array `right` to
      the corresponding position in the current array. After moving, the
     elements in the `right` array are set to default values.
  */
  array<T, N> &operator=(array<T, N> &&right) {
    for (size_type i = 0; i < N; i++) {
      m_data[i] = move(right.m_data[i]);
      right.m_data[i] = {};
    }
    return *this;
  }

  /*
      Equality comparison operator for comparing two arrays.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to compare with.

      Returns:
          - True if the current array is equal to the `right` array, false
     otherwise.

      This equality comparison operator compares each element of the current
     array with the corresponding element of the `right` array. If any pair of
     elements are not equal, it returns false. Otherwise, it returns true.
  */
  bool operator==(const array<T, N> &right) const {
    return equal(begin(), end(), right.begin(), right.end());
  }

  /*
      Inequality comparison operator for comparing two arrays.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to compare with.

      Returns:
          - True if the current array is not equal to the `right` array, false
     otherwise.

      This inequality comparison operator negates the result of the equality
     comparison operator. It returns true if the current array is not equal to
     the `right` array, and false otherwise.
  */
  bool operator!=(const array<T, N> &right) const { return !(*this == right); }

  /*
      Less-than comparison operator for comparing two arrays lexicographically.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to compare with.

      Returns:
          - True if the current array is lexicographically less than the `right`
     array, false otherwise.

      This less-than comparison operator compares the current array with the
     `right` array lexicographically. It uses the lexicographical comparison
     function to perform the comparison between the elements of the two arrays.
  */
  bool operator<(const array<T, N> &right) const {
    return lexicographical_compare(begin(), end(), right.begin(), right.end());
  }

  /*
      Greater-than comparison operator for comparing two arrays
     lexicographically.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to compare with.

      Returns:
          - True if the current array is lexicographically greater than the
     `right` array, false otherwise.

      This greater-than comparison operator compares the `right` array with the
     current array lexicographically. It uses the lexicographical comparison
     function to perform the comparison between the elements of the two arrays.
  */
  bool operator>(const array<T, N> &right) const {
    return lexicographical_compare(right.begin(), right.end(), begin(), end());
  }

  /*
      Less-than or equal-to comparison operator for comparing two arrays.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to compare with.

      Returns:
          - True if the current array is lexicographically less than or equal to
     the `right` array, false otherwise.

      This less-than or equal-to comparison operator compares the current array
     with the `right` array lexicographically. It uses the lexicographical
     comparison function to perform the comparison between the elements of the
     two arrays. If the arrays are equal, it returns true.
  */
  bool operator<=(const array<T, N> &right) const {
    return lexicographical_compare(begin(), end(), right.begin(),
                                   right.end()) ||
           *this == right;
  }

  /*
      Greater-than or equal-to comparison operator for comparing two arrays.

      Template Parameters:
          - None.

      Parameters:
          - right: The array to compare with.

      Returns:
          - True if the current array is lexicographically greater than or equal
     to the `right` array, false otherwise.

      This greater-than or equal-to comparison operator compares the `right`
     array with the current array lexicographically. It uses the lexicographical
     comparison function to perform the comparison between the elements of the
     two arrays. If the arrays are equal, it returns true.
  */
  bool operator>=(const array<T, N> &right) const {
    return lexicographical_compare(right.begin(), right.end(), begin(),
                                   end()) ||
           *this == right;
  }

public:
  value_type m_data[N] = {value_type()};
};

template <typename T> struct array<T, 0> {
  using value_type = T;
  using const_iterator = const value_type *;
  using const_pointer = const value_type *;
  using const_reference = const value_type &;
  using const_reverse_iterator = internal::reverse_iterator<const_iterator>;
  using difference_type = std::ptrdiff_t;
  using iterator = value_type *;
  using pointer = value_type *;
  using reference = value_type &;
  using reverse_iterator = internal::reverse_iterator<iterator>;
  using size_type = std::size_t;

  reference at(size_type off) {
    throw std::out_of_range(
        "Error: Array index out of range. Please ensure the index is within "
        "the valid range.");
    return nullptr;
  }

  const_reference at(size_type off) const {
    throw std::out_of_range(
        "Error: Array index out of range. Please ensure the index is within "
        "the valid range.");
    return nullptr;
  }

  reference back() { return nullptr; }

  const_reference back() const { return nullptr; }

  iterator begin() { return nullptr; }

  const_iterator begin() const { return nullptr; }

  const_iterator cbegin() const { return nullptr; }

  const_reverse_iterator crbegin() const {
    return const_reverse_iterator(nullptr);
  }

  const_iterator cend() const { return nullptr; }

  const_reverse_iterator crend() const {
    return const_reverse_iterator(nullptr);
  }

  pointer data() { return nullptr; }
  const_pointer data() const { return nullptr; }

  iterator end() { return nullptr; }
  const_iterator end() const { return nullptr; }
  bool empty() const { return true; }
  reference front() { return *data(); }
  const_reference front() const { return *data(); }
  size_type max_size() const { return 0; }
  reverse_iterator rbegin() { return reverse_iterator(nullptr); }
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(nullptr);
  }
  reverse_iterator rend() { return reverse_iterator(nullptr); }
  const_reverse_iterator rend() const {
    return const_reverse_iterator(nullptr);
  }
  size_type size() const { return 0; }
  void fill(const_reference val) {}
  void swap(array<T, 0> &right) {}
  reference operator[](size_type off) { return *data(); }
  const_reference operator[](size_type off) const { return *data(); }
};
} // namespace open_stl
#endif // OPEN_STL_ARRAY_
