#ifndef OPEN_STL_UTILITY_H_
#define OPEN_STL_UTILITY_H_

namespace open_stl {
/*
    Performs a cast to an rvalue reference, enabling move semantics.

    Template Parameters:
        - T: The type of the value.

    Parameters:
        - val: The value to be casted to an rvalue reference.

    Returns:
        - An rvalue reference to the input value.

    This function enables move semantics by allowing the value of an lvalue to
   be "moved" to an rvalue reference, avoiding unnecessary copies.
*/
template <typename T> inline T &&move(const T &val) { return (T &&)val; }

/*
    Swaps the values of two objects of the same type.

    Parameters:
        - a: The first object.
        - b: The second object.

    This function swaps the values of two objects of the same type using move
   semantics. It exchanges the contents of 'a' and 'b' efficiently, avoiding
   unnecessary copies. Note that 'T' must support move assignment for this
   function to work correctly.
*/
template <typename T> void swap(T &a, T &b) {
  T temp = move(a);
  a = move(b);
  b = move(temp);
}

} // namespace open_stl

#endif // OPEN_STL_UTILITY_H_