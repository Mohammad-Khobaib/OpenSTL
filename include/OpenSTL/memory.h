#ifndef OPEN_STL_MEMORY_H_
#define OPEN_STL_MEMORY_H_

#include <OpenSTL/utility.h>

#include <cstddef>

namespace open_stl {
template <typename T>
class allocator {
 public:
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using size_type = std::size_t;
  using const_pointer = const T *;
  using difference_type = std::ptrdiff_t;
  using const_reference = const T &;

  pointer address(const_reference val, const void *hint = nullptr) const {
    return &val;
  }

  /**
   * Allocates uninitialized storage for a specified number of objects of type
   * T.
   *
   * Template Parameters:
   *     - None.
   *
   * Parameters:
   *     - count: The number of objects of type T to allocate storage for.
   *
   * Returns:
   *     - A pointer to the beginning of the allocated uninitialized storage for
   * the specified number of objects.
   *
   * Throws:
   *     - std::bad_alloc: If the allocation fails.
   *
   * This function allocates memory sufficient to hold `count` objects of type
   * T. The memory allocated is uninitialized, meaning that the constructors for
   * the objects of type T are not called. This is consistent with the behavior
   * expected from a custom allocator in C++.
   */
  pointer allocate(size_type count) { return new T[count]; }

  void construct(pointer ptr, const_reference val) { *ptr = val; }

  void construct(pointer ptr, T &&val) { *ptr = move(val); }

  template <typename... Other>
  void construct(pointer ptr, Other &&...values) {
    *ptr = T(values...);
  }

  void deallocate(pointer ptr) { delete[] ptr; }

  void destroy(pointer ptr) { ptr->T::~T(); }
};
}  // namespace open_stl

#endif  // OPEN_STL_MEMORY_H_