# Tree Data Structure with Complex Numbers

This project implements a k-ary tree data structure with a default binary tree configuration in C++. It includes basic operations for complex numbers and tree traversal methods. The project demonstrates building and manipulating trees with nodes containing various data types, such as `double` and `Complex` numbers.

## Project Structure

- **Complex.hpp**: Defines the `Complex` class with basic operations for complex numbers, including equality, inequality, and streaming support.
- **node.hpp**: Contains the definition of the `Node` class template, which represents a node in the tree. Nodes can have children stored in a vector.
- **tree.hpp**: Defines the `Tree` class template, supporting k-ary trees with various traversal methods, including pre-order, post-order, and in-order.
- **TreeVisualizer.hpp**: Provides visualization functionalities for the tree (implementation not included in the provided files).
- **doctest.h**: Header for the Doctest framework used for testing.
- **Demo.cpp**: A demonstration program showing how to create and manipulate a binary tree with `double` values.
- **test.cpp**: Contains tests for tree operations using the Doctest framework.

## Build and Run Instructions

### Prerequisites

- **g++**: A C++ compiler supporting C++17.
- **SFML**: Simple and Fast Multimedia Library (required for linking in the Makefile).

### Building the Project

1. To compile the project, use the provided `Makefile`. Open a terminal in the project directory and run:
    ```bash
    make
    ```
    This will build two executables: `demo` and `test_tree`.

2. To clean up the build directory, run:
    ```bash
    make clean
    ```

### Running the Programs

- **Demo Program**: To run the demo program and see tree operations in action:
    ```bash
    ./demo
    ```

- **Tests**: To run the tests for the tree operations:
    ```bash
    make test
    ./test_tree
    ```

## Features

- **Complex Numbers**: The `Complex` class supports basic operations and can be used as node values in the tree.
- **Tree Operations**: The `Tree` class provides various traversal methods and supports k-ary tree configurations.
- **Demo and Tests**: A demo program and test cases are provided to demonstrate and verify the functionality.

## Notes

- Ensure you have SFML installed on your system for the project to link successfully.
- The tree visualization features depend on `TreeVisualizer.hpp`.
