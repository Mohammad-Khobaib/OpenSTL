cmake_minimum_required(VERSION 3.29.3)

project(OpenSTL)
enable_testing()
# Compiler Configuration
set(CMAKE_CXX_STANDARD 17)  # Use C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)

file(GLOB_RECURSE 
    FORMAT_SOURCES
    LIST_DIRECTORIES false 
    "${PROJECT_SOURCE_DIR}/include/OpenSTL/*.h"
    "${PROJECT_SOURCE_DIR}/include/OpenSTL/internal/*.h"
    "${PROJECT_SOURCE_DIR}/test/*.cpp")

find_program(CLANG-FORMAT_PATH clang-format REQUIRED)
add_custom_target(format-code
                    COMMAND ${CLANG-FORMAT_PATH} -i ${FORMAT_SOURCES}
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    COMMENT "Running clang format...")