#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Complex.hpp"
#include "node.hpp"
#include "tree.hpp"
#include <vector>

TEST_CASE("Binary tree operations")
{
    // Create a binary tree with double values
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    SUBCASE("Pre-order traversal")
    {
        // Pre-order traversal expected result
        std::vector<double> expected_pre_order = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        std::vector<double> pre_order_result;

        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
        {
            pre_order_result.push_back(it->get_key());
        }

        CHECK(pre_order_result == expected_pre_order);
    }

    SUBCASE("Post-order traversal")
    {
        // Post-order traversal expected result
        std::vector<double> expected_post_order = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
        std::vector<double> post_order_result;

        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
        {
            post_order_result.push_back(it->get_key());
        }

        CHECK(post_order_result == expected_post_order);
    }

    SUBCASE("In-order traversal")
    {
        // In-order traversal expected result
        std::vector<double> expected_in_order = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
        std::vector<double> in_order_result;

        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
        {
            in_order_result.push_back(it->get_key());
        }

        CHECK(in_order_result == expected_in_order);
    }

    SUBCASE("BFS traversal")
    {
        // BFS traversal expected result
        std::vector<double> expected_bfs = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        std::vector<double> bfs_result;

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            bfs_result.push_back(it->get_key());
        }

        CHECK(bfs_result == expected_bfs);
    }

    SUBCASE("DFS traversal")
    {
        // DFS traversal expected result
        std::vector<double> expected_dfs = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        std::vector<double> dfs_result;

        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
        {
            dfs_result.push_back(it->get_key());
        }

        CHECK(dfs_result == expected_dfs);
    }

    SUBCASE("Heap transformation")
    {
        // Heap transformation expected result
        tree.myHeap();
        std::vector<double> expected_heap = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        std::vector<double> heap_result;

        for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it)
        {
            heap_result.push_back(it->get_key());
        }

        CHECK(heap_result == expected_heap);
    }
}

TEST_CASE("3-ary tree operations")
{
    // Create a 3-ary tree with double values
    Node<double> root_node = Node<double>(1.1);
    Tree<double, 3> tree;
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Pre-order traversal")
    {
        // Pre-order traversal expected result
        std::vector<double> expected_pre_order = {1.1, 1.2, 1.5, 1.3, 1.6, 1.4};
        std::vector<double> pre_order_result;

        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
        {
            pre_order_result.push_back(it->get_key());
        }

        CHECK(pre_order_result == expected_pre_order);
    }

    SUBCASE("Post-order traversal")
    {
        // Post-order traversal expected result
        std::vector<double> expected_post_order = {1.5, 1.2, 1.6, 1.3, 1.4, 1.1};
        std::vector<double> post_order_result;

        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
        {
            post_order_result.push_back(it->get_key());
        }

        CHECK(post_order_result == expected_post_order);
    }

    SUBCASE("DFS traversal")
    {
        // DFS traversal expected result
        std::vector<double> expected_dfs = {1.1, 1.2, 1.5, 1.3, 1.6, 1.4};
        std::vector<double> dfs_result;

        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
        {
            dfs_result.push_back(it->get_key());
        }

        CHECK(dfs_result == expected_dfs);
    }
}

TEST_CASE("Tree with string values") {
    // Create a tree with string values
    Node<std::string> root_node("shifaa");
    Tree<std::string> tree;
    tree.add_root(root_node);
    Node<std::string> n1("eiad");
    Node<std::string> n2("khatib");
    Node<std::string> n3("aa");
    Node<std::string> n4("bb");
    Node<std::string> n5("cc");
    Node<std::string> n6("dd");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    // The string tree should look like:
    /**
     *       shifaa
     *     /      \
     *   eiad    khatib
     *   /  \      / \
     * aa   bb   cc  dd
     */

    SUBCASE("Pre-order traversal") {
        // Pre-order traversal expected result
        std::vector<std::string> expected_pre_order = {"shifaa", "eiad", "aa", "bb", "khatib", "cc", "dd"};
        std::vector<std::string> pre_order_result;

        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            pre_order_result.push_back(it->get_key());
        }

        CHECK(pre_order_result == expected_pre_order);
    }

    SUBCASE("Post-order traversal") {
        // Post-order traversal expected result
        std::vector<std::string> expected_post_order = {"aa", "bb", "eiad", "cc", "dd", "khatib", "shifaa"};
        std::vector<std::string> post_order_result;

        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            post_order_result.push_back(it->get_key());
        }

        CHECK(post_order_result == expected_post_order);
    }

    SUBCASE("BFS traversal") {
        // BFS traversal expected result
        std::vector<std::string> expected_bfs = {"shifaa", "eiad", "khatib", "aa", "bb", "cc", "dd"};
        std::vector<std::string> bfs_result;

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            bfs_result.push_back(it->get_key());
        }

        CHECK(bfs_result == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        // DFS traversal expected result
        std::vector<std::string> expected_dfs = {"shifaa", "eiad", "aa", "bb", "khatib", "cc", "dd"};
        std::vector<std::string> dfs_result;

        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            dfs_result.push_back(it->get_key());
        }

        CHECK(dfs_result == expected_dfs);
    }

    SUBCASE("Heap transformation") {
        // Heap transformation expected result
        tree.myHeap();
        std::vector<std::string> expected_heap = {"aa", "bb", "cc", "dd", "eiad", "khatib", "shifaa"};
        std::vector<std::string> heap_result;

        for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
            heap_result.push_back(it->get_key());
        }

        CHECK(heap_result == expected_heap);
    }
}

TEST_CASE("Invalid operations on the tree")
{

    SUBCASE("Adding a sub-node to a non-existent parent node")
    {
        Tree<int> tree;
        Node<int> non_existent_parent(999);
        Node<int> child(2);

        // Attempt to add a child to a non-existent parent
        CHECK_THROWS(tree.add_sub_node(non_existent_parent, child));
    }

    SUBCASE("Adding a 5th node to a 4-ary tree")
    {
        Tree<int, 4> tree;
        Node<int> root_node(1);
        tree.add_root(root_node);

        Node<int> child1(2);
        Node<int> child2(3);
        Node<int> child3(4);
        Node<int> child4(5);
        Node<int> extra_child(6);

        tree.add_sub_node(root_node, child1);
        tree.add_sub_node(root_node, child2);
        tree.add_sub_node(root_node, child3);
        tree.add_sub_node(root_node, child4);

        // Attempt to add a fifth child to a 4-ary tree
        CHECK_THROWS(tree.add_sub_node(root_node, extra_child));
    }

    SUBCASE("Adding a 3rd node to a binary tree")
    {
        Tree<int, 2> tree;
        Node<int> root_node(1);
        tree.add_root(root_node);

        Node<int> child1(2);
        Node<int> child2(3);
        Node<int> extra_child(4);

        tree.add_sub_node(root_node, child1);
        tree.add_sub_node(root_node, child2);

        // Attempt to add a third child to a binary tree
        CHECK_THROWS(tree.add_sub_node(root_node, extra_child));
    }

    SUBCASE("Adding a root when one already exists")
    {
        Tree<int> tree;
        Node<int> root_node(1);
        tree.add_root(root_node);

        Node<int> new_root(999);

        // Attempt to add a new root when one already exists
        CHECK_THROWS(tree.add_root(new_root));
    }

    SUBCASE("Heap transformation on non-binary tree")
    {
        Tree<int, 3> tree;
        Node<int> root_node(1);
        tree.add_root(root_node);

        Node<int> child1(2);
        Node<int> child2(3);
        Node<int> child3(4);

        tree.add_sub_node(root_node, child1);
        tree.add_sub_node(root_node, child2);
        tree.add_sub_node(root_node, child3);

        // Attempt to transform a non-binary tree to a heap
        CHECK_THROWS(tree.myHeap());
    }
}

TEST_CASE("Complex tree operations") {
    // Create a binary tree with Complex values
    Complex root_complex(1.1, 2.2);
    Complex c1(-1.2, 2.0);
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

    SUBCASE("Pre-order traversal") {
        std::vector<Complex> expected_pre_order = {root_complex, c1, c3, c4, c2, c5};
        std::vector<Complex> pre_order_result;

        for (auto it = complex_tree.begin_pre_order(); it != complex_tree.end_pre_order(); ++it) {
            pre_order_result.push_back(it->get_key());
        }

        CHECK(pre_order_result == expected_pre_order);
    }

    SUBCASE("Post-order traversal") {
        std::vector<Complex> expected_post_order = {c3, c4, c1, c5, c2, root_complex};
        std::vector<Complex> post_order_result;

        for (auto it = complex_tree.begin_post_order(); it != complex_tree.end_post_order(); ++it) {
            post_order_result.push_back(it->get_key());
        }

        CHECK(post_order_result == expected_post_order);
    }

    SUBCASE("In-order traversal") {
        std::vector<Complex> expected_in_order = {c3, c1, c4, root_complex, c5, c2};
        std::vector<Complex> in_order_result;

        for (auto it = complex_tree.begin_in_order(); it != complex_tree.end_in_order(); ++it) {
            in_order_result.push_back(it->get_key());
        }

        CHECK(in_order_result == expected_in_order);
    }

    SUBCASE("BFS traversal") {
        std::vector<Complex> expected_bfs = {root_complex, c1, c2, c3, c4, c5};
        std::vector<Complex> bfs_result;

        for (auto it = complex_tree.begin_bfs_scan(); it != complex_tree.end_bfs_scan(); ++it) {
            bfs_result.push_back(it->get_key());
        }

        CHECK(bfs_result == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        std::vector<Complex> expected_dfs = {root_complex, c1, c3, c4, c2, c5};
        std::vector<Complex> dfs_result;

        for (auto it = complex_tree.begin_dfs_scan(); it != complex_tree.end_dfs_scan(); ++it) {
            dfs_result.push_back(it->get_key());
        }

        CHECK(dfs_result == expected_dfs);
    }

    SUBCASE("Heap traversal") {
        complex_tree.myHeap();
        std::vector<Complex> expected_heap = {c1, root_complex,c2, c3, c4, c5};
        std::vector<Complex> heap_result;

        for (auto it = complex_tree.begin_heap(); it != complex_tree.end_heap(); ++it) {
            heap_result.push_back(it->get_key());
        }

        CHECK(heap_result == expected_heap);
    }
}

TEST_CASE("Heap transformation in binary tree") {

    // The  tree should look like:
    /**
     *         5
     *     /      \   
     *    2        6
     *   /  \      / 
     * 1     3    4 
     */

     // The min heap should look like:
    /**
     *        1
     *     /      \   
     *    2        3
     *   /  \      / 
     * 4    5      6
     */
    Node<double> root_node = Node<double>(5);
    Tree<double> tree;
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(2);
    Node<double> n2 = Node<double>(6);
    Node<double> n3 = Node<double>(1);
    Node<double> n4 = Node<double>(3);
    Node<double> n5 = Node<double>(4);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Heap transformation expected result
    tree.myHeap();
    std::vector<double> expected_heap = {1,2,3,4,5,6};
    std::vector<double> heap_result;

    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
        heap_result.push_back(it->get_key());
    }

    CHECK(heap_result == expected_heap);
}