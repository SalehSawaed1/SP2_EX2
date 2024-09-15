#ifndef TREEVIEW_HPP
#define TREEVIEW_HPP

#include <SFML/Graphics.hpp>  // Include the SFML graphics library
#include "node.hpp"  // Include the node class for tree nodes
#include <cmath>  // Include cmath for mathematical functions
#include <sstream>  // Include sstream for string formatting
#include <memory>  // Include memory for smart pointers
#include <iostream>  // Include iostream for logging

template <typename T>
class TreeVisualizer {
public:
    TreeVisualizer();  // Constructor to initialize the visualizer
    void drawTree(std::shared_ptr<Node<T>> root);  // Draw the entire tree starting from the root
    void render(std::shared_ptr<Node<T>> root);  // Render the tree using SFML

private:
    void drawNode(sf::RenderWindow &window, std::shared_ptr<Node<T>> node, int x, int y, int hSpacing);  // Draw individual node and its children
    sf::RenderWindow window;  // SFML window to display the visualization
    sf::Font font;  // Font for text display inside nodes

    std::string formatKey(T key) const;  // Format the key for display as a string
};

// Constructor to initialize SFML window and font
template <typename T>
TreeVisualizer<T>::TreeVisualizer() {
    window.create(sf::VideoMode(800, 600), "Tree Visualization");  // Create a window with size 800x600 and title "Tree Visualization"

    // Load the font from file, log error if loading fails
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
}

// Draw the tree starting from the root node
template <typename T>
void TreeVisualizer<T>::drawTree(std::shared_ptr<Node<T>> root) {
    if (!root) return;  // If root is null, return

    int windowWidth = window.getSize().x;  // Get window width
    int windowHeight = window.getSize().y;  // Get window height

    drawNode(window, root, windowWidth / 2, 50, windowWidth / 4);  // Start drawing the tree from the root in the center
}

// Render the tree using SFML in a continuous loop
template <typename T>
void TreeVisualizer<T>::render(std::shared_ptr<Node<T>> root) {
    while (window.isOpen()) {  // Keep the window open
        sf::Event event;
        while (window.pollEvent(event)) {  // Process events
            if (event.type == sf::Event::Closed)  // If window is closed, close it
                window.close();
        }

        window.clear(sf::Color::White);  // Clear the window with a white background color
        drawTree(root);  // Draw the tree
        window.display();  // Display the contents of the window
    }
}

// Draw an individual node and recursively draw its children
template <typename T>
void TreeVisualizer<T>::drawNode(sf::RenderWindow &window, std::shared_ptr<Node<T>> node, int x, int y, int hSpacing) {
    if (!node) return;  // If node is null, return

    sf::CircleShape circle(50);  // Create a circle with radius 50 for the node
    circle.setFillColor(sf::Color(45,208,146));  // Set the color of the circle to light green
    circle.setPosition(x - circle.getRadius(), y - circle.getRadius());  // Position the circle around the center coordinates
    window.draw(circle);  // Draw the circle on the window

    // Prepare text to display inside the node
    sf::Text text;
    text.setFont(font);  // Set the font for the text
    text.setString(formatKey(node->get_key()));  // Set the formatted key as the text
    text.setCharacterSize(18);  // Set the size of the text
    text.setFillColor(sf::Color::Black);  // Set the text color to black

    // Center the text inside the circle
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(x - 1, y - 1);  // Adjust position slightly to center the text

    window.draw(text);  // Draw the text

    // Draw lines connecting the node to its children and recursively draw the children
    int childX = x - hSpacing * (node->children.size() - 1) / 2;  // Calculate the starting x position for the children
    int childY = y + 120;  // Set the vertical spacing between parent and children

    for (auto child : node->children) {  // Iterate over each child node
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),  // Start of the line at the parent node
            sf::Vertex(sf::Vector2f(childX, childY))  // End of the line at the child node
        };
        window.draw(line, 2, sf::Lines);  // Draw the line between the parent and the child

        drawNode(window, child, childX, childY, hSpacing / 2);  // Recursively draw the child node
        childX += hSpacing;  // Move to the next horizontal position for the next child
    }
}

// Format the key value as a string for display inside the node
template <typename T>
std::string TreeVisualizer<T>::formatKey(T key) const {
    std::ostringstream oss;  // Create a string stream
    oss << key;  // Write the key value to the stream
    return oss.str();  // Return the formatted string
}

#endif // TREEVIEW_HPP
