# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I./src -I./src/engine `sdl2-config --cflags`
LDFLAGS := `sdl2-config --libs` -lSDL2_mixer -lSDL2_image -lSDL2_ttf -pthread -llua

# Directories
SRC_DIR := src
OBJ_DIR := obj
ENGINE_SRC_DIR := $(SRC_DIR)/engine
ENGINE_OBJ_DIR := $(OBJ_DIR)/engine

# Output executable
TARGET := releases/openmother

# Source and object files
MAIN_SRC := $(SRC_DIR)/main.cpp

# Recursively find all .cpp files in src/engine and its subdirectories
ENGINE_SRCS := $(wildcard $(ENGINE_SRC_DIR)/**/*.cpp) $(wildcard $(ENGINE_SRC_DIR)/*.cpp)
SRCS := $(MAIN_SRC) $(ENGINE_SRCS)

# Object files
MAIN_OBJ := $(OBJ_DIR)/main.o
ENGINE_OBJS := $(patsubst $(ENGINE_SRC_DIR)/%.cpp, $(ENGINE_OBJ_DIR)/%.o, $(ENGINE_SRCS))
OBJS := $(MAIN_OBJ) $(ENGINE_OBJS)

# Rules
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	@mkdir -p releases  # Ensure the releases directory exists
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build main.o
$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build engine object files
$(ENGINE_OBJ_DIR)/%.o: $(ENGINE_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Ensure that the specific subdirectory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
