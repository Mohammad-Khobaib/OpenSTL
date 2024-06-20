# Contributing to OpenSTL

Thank you for your interest in contributing to OpenSTL! We welcome contributions from the community and are excited to collaborate with you. Please take a moment to review this guide to help streamline the contribution process.

## Table of Contents
1. [Code of Conduct](#code-of-conduct)
2. [Getting Started](#getting-started)
3. [Development Environment](#development-environment)
4. [Code Style](#code-style)

## Code of Conduct

This project adheres to the Contributor Covenant Code of Conduct. By participating, you are expected to uphold this code. Please report unacceptable behavior to [mohammadkhobaib529@gmail.com].

## Getting Started

1. **Fork the repository:**

Go to the GitHub page for the repository and click the "Fork" button at the top right.

2. **Clone your fork:**

Open a terminal and run:
```sh
git clone https://github.com/your-username/OpenSTL.git
cd OpenSTL
```

## Development Environment

We support Visual Studio Code 2022 as the primary development environment.

### 1. Install VSCode 2022

Download and install Visual Studio Code 2022 from [here](https://visualstudio.microsoft.com/vs/).

### 2. Install Visual Studio Code

Download and install Visual Studio Code 2022 from [here](https://code.visualstudio.com/).

### 3. Install MinGW for clang-format and ctest

Download and install MinGW from [here](https://winlibs.com/).

### 4. Install CMake.

Download and install Cmake from [here](https://cmake.org/)

### 5. Configure the Project in VSCode

1. **Open the project folder in VSCode:**
Open VSCode and use the `File -> Open Folder` menu option to open the root directory of your project.

2. **Configure CMake Tools:**
Open the Command Palette and create a build directory:
```sh
mkdir build
```

Navigate to the build directory:
```sh
cd build
```

Configure cmake with MSVC:
```sh
cmake -G "Visual Studio 17 2022" ../
```

Build with CMake:
```sh
cmake --build .
```

Run test cases with ctest:
```sh
ctest
```
## Code Style

We follow the Google C++ Style Guide for this project. Please ensure your code adheres to these guidelines to maintain consistency throughout the codebase.


## Implementing Data Structures

We encourage contributors to implement new data structures and algorithms in OpenSTL. Enhancing our collection of data structures not only expands the utility of the library but also enriches the learning and collaboration experience for everyone involved.

### How to Contribute

1. **Choose a Data Structure:**
   - Explore the existing data structures in the project (`/include/OpenSTL`) or suggest a new one.

2. **Implement the Data Structure:**
   - Write clear and efficient code following the Google C++ Style Guide (outlined in `CONTRIBUTING.md`).

3. **Include Tests:**
   - Ensure comprehensive testing of the data structure implementation.
   - Write unit tests using Google Test in the `/test` directory to validate functionality and edge cases.

4. **Submit Your Contribution:**
   - Follow the guidelines in `CONTRIBUTING.md` to fork the repository, create a new branch, and submit a pull request (PR).

### Example Contributions

- Implementing a new container such as a priority queue, hash table, or AVL tree.
- Optimizing existing data structures for performance or memory usage.

### Why Contribute to Data Structures?

- **Learning Opportunity:** Enhance your understanding of algorithms and data structures.
- **Community Impact:** Your contribution helps improve the utility and versatility of OpenSTL for all users.
- **Collaboration:** Engage with the community and receive feedback to improve your coding skills.

### Get Started!

Choose a data structure that interests you and start coding! We look forward to your contributions and appreciate your effort in making OpenSTL a robust library for C++ developers.

---

Thank you for contributing to OpenSTL! 🚀
