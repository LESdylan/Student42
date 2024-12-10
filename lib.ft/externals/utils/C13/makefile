# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
INCLUDE_DIR = include
LIBRARY = $(LIB_DIR)/libft.a

# Test executable
TEST_EXEC = test
TEST_SRC = $(SRC_DIR)/test.c

# Script for building the library
BUILD_SCRIPT = ./build_lib.sh

# Default rule: build library and test executable
all: library $(TEST_EXEC)

# Run the library creation script
library:
	@bash $(BUILD_SCRIPT)

# Build the test executable
$(TEST_EXEC): $(TEST_SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(TEST_SRC) -L$(LIB_DIR) -lft -o $(TEST_EXEC)

# Run the test executable
run: all
	./$(TEST_EXEC)

# Clean the build artifacts
clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/*.a $(TEST_EXEC)

# Fully clean and rebuild
fclean: clean
	rm -rf $(OBJ_DIR) $(LIB_DIR)
	mkdir -p $(OBJ_DIR) $(LIB_DIR)

re: fclean all

.PHONY: all library clean fclean re run
