# including GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Test cases for array class
add_executable(array_test array_test.cpp)
target_link_libraries(array_test PRIVATE  GTest::gtest_main)
gtest_discover_tests(array_test)

# Test cases for algorithms
add_executable(algorithm_test algorithm_test.cpp)
target_link_libraries(algorithm_test PRIVATE  GTest::gtest_main)
gtest_discover_tests(algorithm_test)

# Test cases for memory
add_executable(memory_test memory_test.cpp)
target_link_libraries(memory_test PRIVATE  GTest::gtest_main)
gtest_discover_tests(memory_test)

# Test cases for vector
add_executable(vector_test vector_test.cpp)
target_link_libraries(vector_test PRIVATE  GTest::gtest_main)
gtest_discover_tests(vector_test)