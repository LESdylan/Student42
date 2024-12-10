# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LIB_DIR = lib

# Library files
LIB_SRC = $(SRC_DIR)/ft_create_elem.c $(SRC_DIR)/ft_list_push_front.c $(SRC_DIR)/ft_list_size.c
LIB_OBJ = $(OBJ_DIR)/ft_create_elem.o $(OBJ_DIR)/ft_list_push_front.o $(OBJ_DIR)/ft_list_size.o
LIBRARY = $(LIB_DIR)/libft.a

# Test files
TEST_SRC = $(SRC_DIR)/test.c
TEST_OBJ = $(OBJ_DIR)/test.o
TEST_EXEC = $(OBJ_DIR)/test_ft_list_size

# Rule for creating the library
$(LIBRARY): $(LIB_OBJ)
	ar rcs $(LIBRARY) $(LIB_OBJ)

# Rule for compiling source files to object files for the library
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)   # Create object directory if it doesn't exist
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Rule for building the test executable
$(TEST_EXEC): $(TEST_OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L$(LIB_DIR) -lft -o $(TEST_EXEC)

# Rule for compiling test source files to object files
$(OBJ_DIR)/test.o: $(TEST_SRC) $(LIBRARY)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(TEST_SRC) -o $(OBJ_DIR)/test.o
run:
	$(CC) $(CFLAGS) -I/home/dyl-syzygy/Student42/lib.ft/externals/utils/C12/include/ ./src/test.c ./src/ft_create_elem.c ./src/ft_list_push_front.c -o ./src/test 
	./src/test
# Rule for cleaning object files
clean:
	rm -rf $(OBJ_DIR)

# Rule for cleaning everything (object files, library, and executable)
fclean: clean
	rm -f $(LIBRARY) $(TEST_EXEC)

# Rule for rebuilding everything (clean + build)
re: fclean all

# Default rule (build library and test executable)
all: $(LIBRARY) $(TEST_EXEC)

.PHONY: all clean fclean re


