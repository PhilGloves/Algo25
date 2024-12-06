CC = gcc
CFLAGS = -g -Iinclude -Wall
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TEST_SRC = $(SRC_DIR)/test_ex3.c
COMMON_SRCS = $(filter-out $(TEST_SRC), $(wildcard $(SRC_DIR)/*.c))

TEST_OBJS = $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/test_ex3.o

TEST_TARGET = $(BIN_DIR)/test_ex3

all: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)