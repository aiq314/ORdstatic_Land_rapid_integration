# Compiler
CXX=g++

# Compiler flags
CXXFLAGS=-std=c++17 -Wall -Iinclude  

# Directories
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

# Target executable name
TARGET=$(BIN_DIR)/ordstatic_land2016

# Find all cpp files in the src directory plus the main.cpp file
SOURCES=$(wildcard $(SRC_DIR)/*.cpp) main.cpp
# Convert the .cpp files to .o to specify the object files in the obj directory
OBJECTS=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
# Generate paths for dependency files by replacing the source directory with the object directory in the paths
DEPS=$(OBJECTS:.o=.d)

# Default make target
all: $(TARGET)

# Create the obj/src directory before compiling anything
$(shell mkdir -p $(OBJ_DIR)/src)

# Link the object files into a binary
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile the cpp files into object files
# Rule for main.cpp
$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for other source files
$(OBJ_DIR)/src/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Include dependencies
-include $(DEPS)

# Rule to generate a dependency file by using the C++ preprocessor, including for main.cpp
$(OBJ_DIR)/%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM -MT '$(@:.d=.o)' $< -MF $@

# Adjusted rule for dependency files in the src directory
$(OBJ_DIR)/src/%.d: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MM -MT '$(@:.d=.o)' $< -MF $@
