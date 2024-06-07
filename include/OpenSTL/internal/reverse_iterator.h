#ifndef OPEN_STL_INTERNAL_REVERSE_ITERATOR_H_
#define OPEN_STL_INTERNAL_REVERSE_ITERATOR_H_

#include <OpenSTL/internal/iterator.h>
#include <OpenSTL/type_traits.h>
#include <stddef.h>

namespace open_stl {
namespace internal {
template <typename RandomIterator> class reverse_iterator {
public:
  using difference_type =
      typename iterator_traits<RandomIterator>::difference_type;
  using iterator_type = RandomIterator;
  using pointer = typename iterator_traits<RandomIterator>::pointer;
  using reference = typename iterator_traits<RandomIterator>::reference;

  /*
      Constructor for reverse_iterator.

      Parameters:
          - iterator: Iterator to be reversed.

      Initializes a reverse_iterator with the provided iterator.
  */
  explicit reverse_iterator(const iterator_type &iterator)
      : m_iterator(iterator) {}

  /*
      Retrieve the base iterator.

      Returns:
          The underlying iterator.
  */
  RandomIterator base() const { return m_iterator; }

  /*
      Dereference operator for reverse_iterator.

      Returns:
          A reference to the value pointed to by the underlying iterator.
  */
  reference operator*() const { return *m_iterator; }

  /*
  Addition operator for reverse_iterator.

  Parameters:
      - off: The offset to add.

  Returns:
      A new reverse_iterator resulting from adding the offset to the underlying
  iterator.
  */
  reverse_iterator<RandomIterator> operator+(difference_type off) const {
    return reverse_iterator<RandomIterator>(m_iterator - off);
  }

  /*
      Prefix increment operator for reverse_iterator.

      Returns:
          A reference to the incremented reverse_iterator.
  */
  reverse_iterator<RandomIterator> &operator++() {
    m_iterator--;
    return *this;
  }

  /*
      Postfix increment operator for reverse_iterator.

      Returns:
          A copy of the reverse_iterator before incrementing.
  */
  reverse_iterator<RandomIterator> operator++(int) {
    reverse_iterator<RandomIterator> it = *this;
    ++(*this);
    return it;
  }

  /*
      Addition assignment operator for reverse_iterator.

      Parameters:
          - off: The offset to add.

      Returns:
          A reference to the incremented reverse_iterator.
  */
  reverse_iterator<RandomIterator> &operator+=(difference_type off) {
    m_iterator = m_iterator - off;
    return *this;
  }

  /*
      Subtraction operator for reverse_iterator.

      Parameters:
          - off: The offset to subtract.

      Returns:
          A new reverse_iterator resulting from subtracting the offset from the
     underlying iterator.
  */

  reverse_iterator<RandomIterator> operator-(difference_type off) const {
    return reverse_iterator<RandomIterator>(m_iterator + off);
  }

  /*
      Prefix decrement operator for reverse_iterator.

      Returns:
          A reference to the decremented reverse_iterator.
  */
  reverse_iterator<RandomIterator> &operator--() {
    m_iterator++;
    return *this;
  }

  /*
      Postfix decrement operator for reverse_iterator.

      Returns:
          A copy of the reverse_iterator before decrementing.
  */
  reverse_iterator<RandomIterator> operator--(int) {
    reverse_iterator<RandomIterator> it = *this;
    --(*this);
    return reverse_iterator<RandomIterator>(it);
  }

  /*
      Subtraction assignment operator for reverse_iterator.

      Parameters:
          - off: The offset to subtract.

      Returns:
          A reference to the decremented reverse_iterator.
  */
  reverse_iterator<RandomIterator> &operator-=(difference_type off) {
    m_iterator = m_iterator + off;
    return *this;
  }

  /*
      Member access operator for reverse_iterator.

      Returns:
          A pointer to the underlying iterator's value.
  */
  pointer operator->() const { return &(*m_iterator); }

  /*
      Equality comparison operator for reverse_iterator.

      Parameters:
          - right: The reverse_iterator to compare with.

      Returns:
          True if the iterators are equal, false otherwise.
  */
  bool operator==(const reverse_iterator<RandomIterator> &right) const {
    return m_iterator == right.m_iterator;
  }

  /*
      Inequality comparison operator for reverse_iterator.

      Parameters:
          - right: The reverse_iterator to compare with.

      Returns:
          True if the iterators are not equal, false otherwise.
  */
  bool operator!=(const reverse_iterator<RandomIterator> &right) const {
    return m_iterator != right.m_iterator;
  }

  /*
      Less-than comparison operator for reverse_iterator.

      Parameters:
          - right: The reverse_iterator to compare with.

      Returns:
          True if the left iterator is less than the right iterator, false
     otherwise.
  */
  bool operator<(const reverse_iterator<RandomIterator> &right) const {
    return m_iterator > right.m_iterator;
  }

  /*
      Less-than-or-equal-to comparison operator for reverse_iterator.

      Parameters:
          - right: The reverse_iterator to compare with.

      Returns:
          True if the left iterator is less than or equal to the right iterator,
     false otherwise.
  */
  bool operator<=(const reverse_iterator<RandomIterator> &right) const {
    return m_iterator >= right.m_iterator;
  }

  /*
      Greater-than comparison operator for reverse_iterator.

      Parameters:
          - right: The reverse_iterator to compare with.

      Returns:
          True if the left iterator is greater than the right iterator, false
     otherwise.
  */
  bool operator>(const reverse_iterator<RandomIterator> &right) const {
    return m_iterator < right.m_iterator;
  }

  /*
      Greater-than-or-equal-to comparison operator for reverse_iterator.

      Parameters:
          - right: The reverse_iterator to compare with.

      Returns:
          True if the left iterator is greater than or equal to the right
     iterator, false otherwise.
  */
  bool operator>=(const reverse_iterator<RandomIterator> &right) const {
    return m_iterator <= right.m_iterator;
  }

private:
  iterator_type m_iterator;
};
} // namespace internal
} // namespace open_stl

#endif // OPEN_STL_INTERNAL_REVERSE_ITERATOR_H_