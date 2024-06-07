# OpenSTL

Welcome to OpenSTL!

This repository is dedicated to creating an open-source and readable version of the C++ Standard Template Library (STL). The primary goal of this project is to provide a platform for learning and practicing the STL by providing an easy-to-understand implementation.

## Overview

The primary goal of this repository is to build an open-source and readable version of the C++ Standard Template Library (STL). The STL is a powerful and essential part of C++ programming, providing various containers, algorithms, and utilities for developers.

## Purpose

- **Readability**: Make the STL codebase more readable and understandable for educational purposes.
- **Learning Tool**: Provide a resource for learning about the internals of the STL and how it works under the hood.
- **Contributions**: Encourage contributions from the community to improve and extend the functionality of the STL implementation.

## Building the Project

The project can be built using CMake, which is a cross-platform build system. Follow these steps to build the project:

### Prerequisites

- CMake: Make sure you have CMake installed on your system. You can download it from [cmake.org](https://cmake.org/download/).

### Build Giude

Follow these steps to build and run the OpenSTL project:

Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/OpenSTL.git
```

Create build directory:

```bash
mkdir build
```

Navigate to build directory:
```bash
cd build
```

Configure cmake:
```bash
cmake ../
```

build the project:
```bash
cmake --build .
```

Run test cases:
```bash
ctest
```
