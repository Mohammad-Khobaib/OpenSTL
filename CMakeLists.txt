# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.29.3)

project(OpenSTL)
enable_testing()
# Compiler Configuration
set(CMAKE_CXX_STANDARD 20)  # Use C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)

# Glob all header and test files, then use clang-format to format them with the Google style.
file(GLOB_RECURSE 
    FORMAT_SOURCES
    LIST_DIRECTORIES false 
    "${PROJECT_SOURCE_DIR}/include/OpenSTL/*.h"
    "${PROJECT_SOURCE_DIR}/include/OpenSTL/internal/*.h"
    "${PROJECT_SOURCE_DIR}/test/*.cpp")

find_program(CLANG-FORMAT_PATH clang-format REQUIRED)
add_custom_target(format-code
                    COMMAND ${CLANG-FORMAT_PATH} -i -style="Google" ${FORMAT_SOURCES}
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    COMMENT "Running clang format...")