CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC_PATH = 3vectors/
OBJ_DIR = obj
BIN_DIR = programa
TARGET = $(BIN_DIR)/main

SRCS = $(wildcard $(SRC_PATH)/*.cpp)
OBJS = $(patsubst $(SRC_PATH)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)