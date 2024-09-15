#ifndef NODE_HPP
#define NODE_HPP

#include <vector>  // Include vector for child nodes
#include <memory>  // Include memory for shared pointers

template <typename T>
class Node {
public:
    T key;  // Key stored in the node
    std::vector<std::shared_ptr<Node<T>>> children;  // Vector of pointers to child nodes

    Node(T k) : key(k) {}  // Constructor to initialize the key

    void add_child(std::shared_ptr<Node<T>> child);  // Function to add a child node

    T get_key() const;  // Function to get the key of the node
};

template <typename T>
void Node<T>::add_child(std::shared_ptr<Node<T>> child) {
    children.push_back(child);  // Add the child node to the children vector
}

template <typename T>
T Node<T>::get_key() const {
    return key;  // Return the key of the node
}



#endif // NODE_HPP
