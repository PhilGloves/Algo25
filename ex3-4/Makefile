CC = gcc
CFLAGS = -g -Iinclude -Wall -I../unity -I../ex3/include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

UNITY_DIR = ../unity
UNITY_SRC = $(UNITY_DIR)/unity.c

HASHTABLE_DIR = ../ex3
HASHTABLE_SRC = $(HASHTABLE_DIR)/src/hash_table.c

MAIN_SRC = $(SRC_DIR)/main_ex3-4.c
TEST_SRC = $(SRC_DIR)/test_ex3-4.c
COMMON_SRCS = $(filter-out $(MAIN_SRC) $(TEST_SRC), $(wildcard $(SRC_DIR)/*.c))

MAIN_OBJS = $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/main_ex3-4.o $(OBJ_DIR)/hash_table.o
TEST_OBJS = $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/test_ex3-4.o $(OBJ_DIR)/unity.o $(OBJ_DIR)/hash_table.o

MAIN_TARGET = $(BIN_DIR)/main_ex3-4
TEST_TARGET = $(BIN_DIR)/test_ex3-4

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

$(OBJ_DIR)/hash_table.o: $(HASHTABLE_SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)