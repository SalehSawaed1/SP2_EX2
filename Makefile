# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17  -I.

# Linker flags for SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS_DEMO = Demo.cpp Complex.cpp node.cpp tree.cpp 
SRCS_TEST = test.cpp Complex.cpp node.cpp tree.cpp

# Object files
OBJS_DEMO = $(SRCS_DEMO:.cpp=.o)
OBJS_TEST = $(SRCS_TEST:.cpp=.o)

# Target executables
TARGET_DEMO = demo
TARGET_TEST = test_tree

# Default target to build all targets
all: $(TARGET_DEMO) $(TARGET_TEST)

# Build tree executable
tree: $(TARGET_DEMO)

# Build demo executable
$(TARGET_DEMO): $(OBJS_DEMO)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build test executable
$(TARGET_TEST): $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run the tests
test: $(TARGET_TEST)
	./$(TARGET_TEST)

# Clean up the build directory
clean:
	rm -f $(OBJS_DEMO) $(OBJS_TEST) $(TARGET_DEMO) $(TARGET_TEST)

# Compile individual source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies
Demo.o: node.hpp tree.hpp TreeVisualizer.hpp Complex.hpp
TreeVisualizer.o: TreeVisualizer.hpp
test.o: doctest.h node.hpp tree.hpp Complex.hpp
Complex.o: Complex.hpp
node.o: node.hpp
tree.o: tree.hpp

.PHONY: all clean test tree