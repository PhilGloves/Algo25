CC = gcc
CFLAGS = -g -Iinclude -Wall -I../unity
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

UNITY_DIR = ../unity
UNITY_SRC = $(UNITY_DIR)/unity.c

MAIN_SRC = $(SRC_DIR)/main_ex2.c
TEST_SRC = $(SRC_DIR)/test_ex2.c
COMMON_SRCS = $(filter-out $(MAIN_SRC) $(TEST_SRC), $(wildcard $(SRC_DIR)/*.c))

MAIN_OBJS = $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/main_ex2.o
TEST_OBJS = $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/test_ex2.o $(OBJ_DIR)/unity.o

MAIN_TARGET = $(BIN_DIR)/main_ex2
TEST_TARGET = $(BIN_DIR)/test_ex2

all: $(MAIN_TARGET) $(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_TARGET): $(TEST_OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/unity.o: $(UNITY_SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

