
![Screenshot from 2024-09-15 14-02-39](https://github.com/user-attachments/assets/68b896ab-66fb-407d-8e8e-ca43be2df24c)

# K-Tree Data Structure with Visualization and Traversal

This project implements a k-ary tree data structure with a default binary tree configuration in C++. It includes basic operations for complex numbers and tree traversal methods. The project demonstrates building and manipulating trees with nodes containing various data types, such as `double` and `Complex` numbers.

## Project Structure

- **Complex.hpp**: Defines the `Complex` class with basic operations for complex numbers, including equality, inequality, and streaming support.
- **node.hpp**: Contains the definition of the `Node` class template, which represents a node in the tree. Nodes can have children stored in a vector.
- **tree.hpp**: Defines the `Tree` class template, supporting k-ary trees with various traversal methods, including pre-order, post-order, and in-order.
- **TreeVisualizer.hpp**: Provides visualization functionalities for the tree (implementation not included in the provided files).
- **doctest.h**: Header for the Doctest framework used for testing.
- **Demo.cpp**: A demonstration program showing how to create and manipulate a binary tree with `double` values.
- **test.cpp**: Contains tests for tree operations using the Doctest framework.

- **Tree Class**
  - `Tree()`: Constructs a tree with the given maximum number of children per node.
  - `int get_k() const`: Returns the maximum number of children per node.
  - `void add_root(const Node<T>& node)`: Adds a root node to the tree.
  - `void add_sub_node(const Node<T>& parent, const Node<T>& child)`: Adds a child node to a specified parent node.
  - `iterator begin_pre_order()`: Returns an iterator to the beginning of a pre-order traversal.
  - `iterator end_pre_order()`: Returns an iterator to the end of a pre-order traversal.
  - `iterator begin_post_order()`: Returns an iterator to the beginning of a post-order traversal.
  - `iterator end_post_order()`: Returns an iterator to the end of a post-order traversal.
  - `iterator begin_in_order()`: Returns an iterator to the beginning of an in-order traversal.
  - `iterator end_in_order()`: Returns an iterator to the end of an in-order traversal.
  - `iterator begin_bfs_scan()`: Returns an iterator to the beginning of a BFS traversal.
  - `iterator end_bfs_scan()`: Returns an iterator to the end of a BFS traversal.
  - `iterator begin_dfs_scan()`: Returns an iterator to the beginning of a DFS traversal.
  - `iterator end_dfs_scan()`: Returns an iterator to the end of a DFS traversal.
  - `void myHeap()`: Transforms the binary tree into a min-heap.
  - `iterator begin_heap()`: Returns an iterator to the beginning of the heap.
  - `iterator end_heap()`: Returns an iterator to the end of the heap.
  - `void render()`: Renders the tree using SFML.
  - `std::ostream& operator<<(std::ostream& os, Tree<T, K>& tree)`: Overload the stream insertion operator to launch the GUI for tree visualization.


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
