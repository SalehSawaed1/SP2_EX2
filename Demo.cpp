#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

using namespace std;

int main()
{
    // Create and build a tree with double values
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-order traversal (double tree):" << endl;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        cout << it->get_key() << " ";
    }
    cout << endl; // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Post-order traversal (double tree):" << endl;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        cout << it->get_key() << " ";
    }
    cout << endl; // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In-order traversal (double tree):" << endl;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        cout << it->get_key() << " ";
    }
    cout << endl; // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "BFS traversal (double tree):" << endl;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        cout << it->get_key() << " ";
    }
    cout << endl; // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS traversal (double tree):" << endl;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        cout << it->get_key() << " ";
    }
    cout << endl; // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    // Render the tree using SFML
    cout << tree;

    // Check heap transformation for the double tree
    tree.myHeap();
    cout << "Heap traversal (double tree):" << endl;
    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it)
    {
        cout << it->get_key() << " ";
    }
    cout << endl; // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 (in min-heap order)

    // Create and build a 3-ary tree with double values
    Tree<double, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    // Render the 3-ary tree using SFML
    cout << three_ary_tree;
 
 // Create and build a tree with Complex numbers
Complex root_complex(1.1, 2.2);
Complex c1(1.2, 2.3);
Complex c2(1.3, 2.4);
Complex c3(1.4, 2.5);
Complex c4(1.5, 2.6);
Complex c5(1.6, 2.7);

Node<Complex> root_complex_node(root_complex);
Tree<Complex> complex_tree; // Binary tree that contains Complex numbers.
complex_tree.add_root(root_complex_node);
Node<Complex> complex_n1(c1);
Node<Complex> complex_n2(c2);
Node<Complex> complex_n3(c3);
Node<Complex> complex_n4(c4);
Node<Complex> complex_n5(c5);

complex_tree.add_sub_node(root_complex_node, complex_n1);
complex_tree.add_sub_node(root_complex_node, complex_n2);
complex_tree.add_sub_node(complex_n1, complex_n3);
complex_tree.add_sub_node(complex_n1, complex_n4);
complex_tree.add_sub_node(complex_n2, complex_n5);

// The complex tree should look like:
/**
 *       root = 1.1 + 2.2i
 *     /               \
 * 1.2 + 2.3i       1.3 + 2.4i
 *   /    \           /
 *1.4 + 2.5i  1.5 + 2.6i 1.6 + 2.7i
 */

cout << "Pre-order traversal (complex tree):" << endl;
for (auto it = complex_tree.begin_pre_order(); it != complex_tree.end_pre_order(); ++it)
{
    cout << it->get_key() << " , ";
}
cout << endl; // prints: 1.1 + 2.2i, 1.2 + 2.3i, 1.4 + 2.5i, 1.5 + 2.6i, 1.3 + 2.4i, 1.6 + 2.7i

cout << "Post-order traversal (complex tree):" << endl;
for (auto it = complex_tree.begin_post_order(); it != complex_tree.end_post_order(); ++it)
{
    cout << it->get_key() << " , ";
}
cout << endl; // prints: 1.4 + 2.5i, 1.5 + 2.6i, 1.2 + 2.3i, 1.6 + 2.7i, 1.3 + 2.4i, 1.1 + 2.2i

cout << "In-order traversal (complex tree):" << endl;
for (auto it = complex_tree.begin_in_order(); it != complex_tree.end_in_order(); ++it)
{
    cout << it->get_key() << " , ";
}
cout << endl; // prints: 1.4 + 2.5i, 1.2 + 2.3i, 1.5 + 2.6i, 1.1 + 2.2i, 1.6 + 2.7i, 1.3 + 2.4i

cout << "BFS traversal (complex tree):" << endl;
for (auto it = complex_tree.begin_bfs_scan(); it != complex_tree.end_bfs_scan(); ++it)
{
    cout << it->get_key() << " , ";
}
cout << endl; // prints: 1.1 + 2.2i, 1.2 + 2.3i, 1.3 + 2.4i, 1.4 + 2.5i, 1.5 + 2.6i, 1.6 + 2.7i

cout << "DFS traversal (complex tree):" << endl;
for (auto it = complex_tree.begin_dfs_scan(); it != complex_tree.end_dfs_scan(); ++it)
{
    cout << it->get_key() << "  ,  ";
}
cout << endl; // prints: 1.1 + 2.2i, 1.2 + 2.3i, 1.4 + 2.5i, 1.5 + 2.6i, 1.3 + 2.4i, 1.6 + 2.7i

// Heap transformation
complex_tree.myHeap();
cout << "Heap traversal (complex tree):" << endl;
for (auto it = complex_tree.begin_heap(); it != complex_tree.end_heap(); ++it)
{
    cout << it->get_key() << "  ,  ";
}
cout << endl; // prints: 1.1 + 2.2i, 1.2 + 2.3i, 1.3 + 2.4i, 1.4 + 2.5i, 1.5 + 2.6i, 1.6 + 2.7i

// Render the complex tree 
cout << complex_tree;

    return 0;
}