# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
SRC_FILES = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIB_NAME = libft.a

# Default rule - make all
all: $(LIB_NAME)

# Rule to create the static library
$(LIB_NAME): $(OBJ_FILES)
	@echo "Creating library $(LIB_NAME)"
	@ar rcs $@ $^

# Rule to remove object files
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_FILES)

# Rule to remove object files and the static library
fclean: clean
	@echo "Removing library $(LIB_NAME)..."
	@rm -f $(LIB_NAME)

# Rule to clean and rebuild the library
re: fclean all

# Compile each .c file to an object .o file
%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

.PHONY: all clean fclean re
