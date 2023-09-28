CXX := g++

SRC_DIR := src
INC_DIR := $(SRC_DIR)/inc
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))
EXE := $(BIN_DIR)/sevc

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -I$(INC_DIR) -c $< -o $@

run: $(EXE)
	$(EXE)

clean:
	rm -f $(OBJS) $(EXE)