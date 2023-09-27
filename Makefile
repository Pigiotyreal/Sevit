CXX := g++

SRC_DIR := src
INC_DIR := $(SRC_DIR)/inc
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))
EXES := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(SRCS))

all: $(EXES)

$(BIN_DIR)/%: $(BIN_DIR)/%.o
	$(CXX) $< -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -I$(INC_DIR) -c $< -o $@

run: $(EXES)
	$(EXES)

clean:
	rm -f $(OBJS) $(EXES)