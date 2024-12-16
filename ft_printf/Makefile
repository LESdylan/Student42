# Project name and output
NAME = ft_printf

# Compiler and flags
CC = clang
CFLAGS = -Wall -Werror -Wextra -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
TEST_DIR = testing

# Source files
SRC_FILES = ft_printf.c helpers.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Testing files
TEST_SRC = $(addprefix $(TEST_DIR)/ ,test.c)
TEST_OBJ = $(TEST_SRC:%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Compile object files from source
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything including the binary
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Compile and run tests
test: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o test_runner
	./test_runner

# Compile test object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets to avoid conflicts with files
.PHONY: all clean fclean re test
