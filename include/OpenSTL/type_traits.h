#ifndef OPEN_STL_TYPE_TRAITS_H_
#define OPEN_STL_TYPE_TRAITS_H_

namespace open_stl {
/*
    Template struct to determine if a type is const-qualified.

    Template Parameters:
        - T: The type to be checked.

    Members:
        - value: A boolean indicating whether the type is const-qualified.
                 It is true if the type is const-qualified, false otherwise.

    This struct provides a compile-time constant value indicating whether a
   given type is const-qualified.
*/
template <typename T> struct is_const {
  static constexpr bool value = false;
};

/*
    Template specialization of is_const for const-qualified types.

    Template Parameters:
        - T: The type that is const-qualified.

    Members:
        - value: A boolean indicating whether the type is const-qualified.
                 It is true if the type is const-qualified, false otherwise.

    This specialization provides a compile-time constant value indicating that a
   const-qualified type is indeed const-qualified.
*/
template <typename T> struct is_const<const T> {
  static constexpr bool value = true;
};

template <typename T, typename U> struct is_same {
  static constexpr bool value = false;
};

template <typename T> struct is_same<T, T> {
  static constexpr bool value = true;
};

} // namespace open_stl
#endif // OPEN_STL_TYPE_TRAITS_H_