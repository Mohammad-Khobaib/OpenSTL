#ifndef OPEN_STL_ALGORITHM_H_
#define OPEN_STL_ALGORITHM_H_

namespace open_stl {

/*
    Lexicographically compares two ranges.

    Template Parameters:
        - InputIterator: The type of iterator for the input range.

    Parameters:
        - lhs_begin: The beginning of the left-hand side range.
        - lhs_end: The end of the left-hand side range.
        - rhs_begin: The beginning of the right-hand side range.
        - rhs_end: The end of the right-hand side range.

    Returns:
        - True if the first range is lexicographically less than the second
   range, false otherwise.

    This function compares the elements in two ranges, starting from the
   beginning, until it finds unequal elements or reaches the end of one of the
   ranges.
*/
template <typename InputIterator>
bool lexicographical_compare(InputIterator lhs_begin, InputIterator lhs_end,
                             InputIterator rhs_begin, InputIterator rhs_end) {
  while (lhs_begin != lhs_end && rhs_begin != rhs_end) {
    if (*lhs_begin < *rhs_begin) {
      return true;
    }
    if (*lhs_begin > *rhs_begin) {
      return false;
    }
    ++lhs_begin;
    ++rhs_begin;
  }
  if (lhs_begin == lhs_end && rhs_begin != rhs_end) {
    return true;
  } else {
    return false;
  }
}

/*
    Compares two ranges for equality.

    Template Parameters:
        - InputIterator: The type of iterator for the input ranges.

    Parameters:
        - lhs_begin: The beginning of the left-hand side range.
        - lhs_end: The end of the left-hand side range.
        - rhs_begin: The beginning of the right-hand side range.
        - rhs_end: The end of the right-hand side range.

    Returns:
        - True if the two ranges are equal, false otherwise.

    This function compares the elements in two ranges specified by the input
   iterators. It iterates over both ranges simultaneously, comparing the
   corresponding elements. If any pair of elements differ, it returns false. If
   both ranges have the same length and all corresponding elements are equal, it
   returns true. Otherwise, it returns false.
*/
template <typename InputIterator>
bool equal(InputIterator lhs_begin, InputIterator lhs_end,
           InputIterator rhs_begin, InputIterator rhs_end) {
  while (lhs_begin != lhs_end && rhs_begin != rhs_end) {
    if (*lhs_begin != *rhs_begin) {
      return false;
    }
    ++lhs_begin;
    ++rhs_begin;
  }
  if (lhs_begin == lhs_end && rhs_begin == rhs_end) {
    return true;
  } else {
    return false;
  }
}

} // namespace open_stl

#endif // OPEN_STL_ALGORITHM_H_