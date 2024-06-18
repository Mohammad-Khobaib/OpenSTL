#ifndef OPEN_STL_INTERNAL_ITERATOR_H_
#define OPEN_STL_INTERNAL_ITERATOR_H_

#include <cstddef>

namespace open_stl {

namespace internal {

/*
    Structs representing different categories of iterators.

    Enumerator Tags:
        - input_iterator_tag: An iterator that can be used to read values from a
   range.
        - output_iterator_tag: An iterator that can be used to write values to a
   range.
        - forward_iterator_tag: An iterator that supports both reading and
   writing and can traverse a range forward only.
        - bidirectional_iterator_tag: An iterator that supports reading,
   writing, and bidirectional traversal (both forward and backward).
        - random_access_iterator_tag: An iterator that supports reading,
   writing, and random access traversal.

    These tags provide a way to classify iterators based on their capabilities
   and behavior.
*/
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/*
    Template struct to extract properties of an iterator type.

    Template Parameters:
        - Iterator: The type of the iterator for which properties are extracted.

    Members:
        - iterator_category: The category of the iterator, indicating its
   capabilities and behavior.
        - value_type: The type of the value that the iterator points to.
        - difference_type: The type representing the difference between two
   iterators.
        - pointer: The type of pointer used by the iterator.
        - reference: The type of reference used by the iterator.

    This struct provides a convenient way to access the properties of an
   iterator type, allowing generic code to be written without knowing the exact
   iterator type.
*/
template <typename Iterator>
struct iterator_traits {
  using iterator_category = typename Iterator::iterator_category;
  using value_type = typename Iterator::value_type;
  using difference_type = typename Iterator::difference_type;
  using pointer = typename Iterator::pointer;
  using reference = typename Iterator::reference;
};

/*
    Template specialization for raw pointers to extract properties of the
   iterator.

    Template Parameters:
        - T: The type of the elements pointed to by the pointer.

    Members:
        - value_type: The type of the elements pointed to by the pointer.
        - pointer: Pointer to the type pointed by the iterator.
        - reference: Reference to the type pointed by the iterator.
        - difference_type: Type representing the difference between two
   iterators.

    This specialization is used for raw pointers and provides the necessary
   traits for them.
*/
template <typename T>
struct iterator_traits<T *> {
  using category = random_access_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T *;
  using reference = T &;
};

/*
    Template specialization for constant raw pointers to extract properties of
   the iterator.

    Template Parameters:
        - T: The type of the elements pointed to by the constant pointer.

    Members:
        - value_type: The type of the elements pointed to by the constant
   pointer.
        - pointer: Constant pointer to the type pointed by the iterator.
        - reference: Constant reference to the type pointed by the iterator.
        - difference_type: Type representing the difference between two
   iterators.

    This specialization is used for constant raw pointers and provides the
   necessary traits for them.
*/
template <typename T>
struct iterator_traits<const T *> {
  using value_type = const T;
  using difference_type = std::ptrdiff_t;
  using pointer = const T *;
  using reference = const T &;
};

}  // namespace internal
}  // namespace open_stl

#endif  // OPEN_STL_INTERNAL_ITERATOR_H_
