#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"  // Include the node header file
#include "TreeVisualizer.hpp"  // Include the tree visualizer header
#include <vector>  // Include vector for dynamic arrays
#include <queue>  // Include queue for BFS traversal
#include <stack>  // Include stack for DFS traversal
#include <stdexcept>  // Include for exception handling
#include <algorithm>  // Include for heap transformations
#include <iostream>  // Include for logging errors
#include "string.h"  // Include string operations

template <typename T, int K = 2>
class Tree {

    private:
    std::shared_ptr<Node<T>> root;  // Root node of the tree
    int k;  // Maximum number of children per node
    bool isBinaryTree;  // Flag indicating if the tree is binary

    std::vector<std::shared_ptr<Node<T>>> preOrder_nodes;  // Stores nodes in pre-order
    std::vector<std::shared_ptr<Node<T>>> post_order_nodes;  // Stores nodes in post-order
    std::vector<std::shared_ptr<Node<T>>> inOrder_nodes;  // Stores nodes in in-order
    std::vector<std::shared_ptr<Node<T>>> bfs_nodes;  // Stores nodes in BFS order
    std::vector<std::shared_ptr<Node<T>>> dfs_nodes;  // Stores nodes in DFS order
    std::vector<std::shared_ptr<Node<T>>> heap_nodes;  // Stores nodes in heap order
    public:
    Tree() : root(nullptr), k(K), isBinaryTree(K == 2) {}  // Constructor

    int get_k() const { return k; }  // Return maximum children

    void add_root(const Node<T>& node) {
        if (root == nullptr) {  // If root is not set
            root = std::make_shared<Node<T>>(node.get_key());  // Create root node
        } else {
            throw std::runtime_error("Root node already exists.");  // Throw exception if root exists
        }
    }

    void add_sub_node(const Node<T>& parent, const Node<T>& child) {
        if (root == nullptr) throw std::runtime_error("Root node not found.");  // If no root, throw error
        std::queue<std::shared_ptr<Node<T>>> q;  // Create queue for BFS
        q.push(root);  // Push root node into queue
        std::shared_ptr<Node<T>> parent_ptr = nullptr;  // Initialize parent pointer
        while (!q.empty()) {
            std::shared_ptr<Node<T>> node = q.front();  // Get front node
            q.pop();  // Remove node from queue
            if (node->get_key() == parent.get_key()) {  // If keys match
                parent_ptr = node;  // Set parent pointer
                break;  // Exit loop
            }
            for (auto& child_node : node->children) {  // Loop over children
                q.push(child_node);  // Push child into queue
            }
        }
        if (parent_ptr == nullptr) throw std::runtime_error("Parent node not found.");  // If parent not found
        if (parent_ptr->children.size() >= static_cast<size_t>(k)) {  // If max children reached
            throw std::runtime_error("Max children reached.");  // Throw error
        }
        parent_ptr->add_child(std::make_shared<Node<T>>(child));  // Add child to parent
    }

    class iterator {
    private:
        typename std::vector<std::shared_ptr<Node<T>>>::iterator it;  // Iterator for vector

    public:
        iterator(typename std::vector<std::shared_ptr<Node<T>>>::iterator iter) : it(iter) {}  // Constructor

        iterator& operator++() { ++it; return *this; }  // Increment iterator

        bool operator!=(const iterator& other) const { return it != other.it; }  // Compare iterators

        Node<T>& operator*() const { return **it; }  // Dereference iterator

        Node<T>* operator->() const { return it->get(); }  // Access node
    };

    iterator begin_pre_order() {
        preOrder_nodes.clear();  // Clear pre-order list
        pre_order_traversal(root);  // Perform pre-order traversal
        return iterator(preOrder_nodes.begin());  // Return iterator to beginning
    }

    iterator end_pre_order() { return iterator(preOrder_nodes.end()); }  // Return iterator to end

    iterator begin_post_order() {
        post_order_nodes.clear();  // Clear post-order list
        post_order_traversal(root);  // Perform post-order traversal
        return iterator(post_order_nodes.begin());  // Return iterator to beginning
    }

    iterator end_post_order() { return iterator(post_order_nodes.end()); }  // Return iterator to end

    iterator begin_in_order() {
        inOrder_nodes.clear();  // Clear in-order list
        in_order_traversal(root);  // Perform in-order traversal
        return iterator(inOrder_nodes.begin());  // Return iterator to beginning
    }

    iterator end_in_order() { return iterator(inOrder_nodes.end()); }  // Return iterator to end

    iterator begin_bfs_scan() {
        bfs_nodes.clear();  // Clear BFS list
        bfs_traversal(root);  // Perform BFS traversal
        return iterator(bfs_nodes.begin());  // Return iterator to beginning
    }

    iterator end_bfs_scan() { return iterator(bfs_nodes.end()); }  // Return iterator to end

    iterator begin_dfs_scan() {
        dfs_nodes.clear();  // Clear DFS list
        dfs_traversal(root);  // Perform DFS traversal
        return iterator(dfs_nodes.begin());  // Return iterator to beginning
    }

    iterator end_dfs_scan() { return iterator(dfs_nodes.end()); }  // Return iterator to end

    void myHeap() {
        if (K != 2) throw std::runtime_error("Heap transformation only for binary trees.");  // Error if not binary
        heap_nodes.clear();  // Clear heap list
        std::queue<std::shared_ptr<Node<T>>> q;  // Create queue
        if (root) q.push(root);  // Push root to queue
        while (!q.empty()) {
            std::shared_ptr<Node<T>> current = q.front();  // Get front node
            q.pop();  // Remove node from queue
            heap_nodes.push_back(current);  // Add node to heap list
            for (auto child : current->children) {  // Loop over children
                q.push(child);  // Push child to queue
            }
        }
        auto compare = [](std::shared_ptr<Node<T>> a, std::shared_ptr<Node<T>> b) { return a->key < b->key; };  // Compare nodes
        std::make_heap(heap_nodes.begin(), heap_nodes.end(), compare);  // Transform to heap
        std::sort_heap(heap_nodes.begin(), heap_nodes.end(), compare);  // Sort heap
        for (size_t i = 0; i < heap_nodes.size(); ++i) {
            heap_nodes[i]->children.clear();  // Clear children
            size_t left_index = 2 * i + 1;  // Calculate left child index
            size_t right_index = 2 * i + 2;  // Calculate right child index
            if (left_index < heap_nodes.size()) heap_nodes[i]->children.push_back(heap_nodes[left_index]);  // Add left child
            if (right_index < heap_nodes.size()) heap_nodes[i]->children.push_back(heap_nodes[right_index]);  // Add right child
        }
        root = heap_nodes.empty() ? nullptr : heap_nodes[0];  // Set root
    }

    iterator begin_heap() {
        myHeap();  // Perform heap transformation
        return iterator(heap_nodes.begin());  // Return iterator to beginning
    }

    iterator end_heap() { return iterator(heap_nodes.end()); }  // Return iterator to end

    void render() {
        TreeVisualizer<T> t;  // Create visualizer
        t.render(root);  // Render tree
    }

    friend std::ostream& operator<<(std::ostream& os, Tree<T, K>& tree) {
        tree.render();  // Render tree using operator<<
        return os;
    }


    void pre_order_traversal(std::shared_ptr<Node<T>> node) {
        if (!node) return;  // Base case: if node is null, return
        preOrder_nodes.push_back(node);  // Add node to pre-order list
        for (auto child : node->children) {  // Loop over child nodes
            pre_order_traversal(child);  // Recursive call for each child
        }
    }

    void post_order_traversal(std::shared_ptr<Node<T>> node) {
        if (!node) return;  // Base case: if node is null, return
        for (auto child : node->children) {  // Loop over child nodes
            post_order_traversal(child);  // Recursive call for each child
        }
        post_order_nodes.push_back(node);  // Add node to post-order list
    }

    void in_order_traversal(std::shared_ptr<Node<T>> node) {
        if (!node || K != 2) return;  // If node is null or not a binary tree, return
        if (!node->children.empty()) {  // If node has children
            in_order_traversal(node->children[0]);  // Traverse left child (first child)
        }
        inOrder_nodes.push_back(node);  // Add node to in-order list
        if (node->children.size() > 1) {  // If node has more than one child
            in_order_traversal(node->children[1]);  // Traverse right child (second child)
        }
    }

    void bfs_traversal(std::shared_ptr<Node<T>> node) {
        if (!node) return;  // If node is null, return
        std::queue<std::shared_ptr<Node<T>>> q;  // Create queue for BFS
        q.push(node);  // Push root node into queue
        while (!q.empty()) {
            std::shared_ptr<Node<T>> current = q.front();  // Get front node
            q.pop();  // Remove node from queue
            bfs_nodes.push_back(current);  // Add node to BFS list
            for (auto child : current->children) {  // Loop over child nodes
                q.push(child);  // Push each child into queue
            }
        }
    }

    void dfs_traversal(std::shared_ptr<Node<T>> node) {
        if (!node) return;  // If node is null, return
        std::stack<std::shared_ptr<Node<T>>> s;  // Create stack for DFS
        s.push(node);  // Push root node into stack
        while (!s.empty()) {
            std::shared_ptr<Node<T>> current = s.top();  // Get top node
            s.pop();  // Remove node from stack
            dfs_nodes.push_back(current);  // Add node to DFS list
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {  // Loop in reverse order
                s.push(*it);  // Push each child into stack
            }
        }
    }
};

#endif // TREE_HPP
