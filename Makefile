# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = src
OBJ_DIR = obj
RELEASE_DIR = releases
OBJ_ENGINE_DIR = $(OBJ_DIR)/engine

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/engine/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXEC = $(RELEASE_DIR)/openmother

# SDL2 flags (ensure you have SDL2 installed)
SDL2_FLAGS = `sdl2-config --cflags --libs`

# Targets
all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(EXEC) $(SDL2_FLAGS)

# Rule for creating object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the obj/engine directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_ENGINE_DIR)

# Clean up
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

.PHONY: all clean
