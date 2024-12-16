# Name of the executable
NAME = get_next_line

# Source files
SRC = src/get_next_line.c
TEST_SRC = testing/test.c
LIBFT_SRC = libft/ft_strlen.c \
           libft/ft_strchr.c \
           libft/ft_strdup.c

# Object files (in the obj directory)
OBJ = $(SRC:%.c=obj/%.o)
TEST_OBJ = $(TEST_SRC:%.c=obj/%.o)
LIBFT_OBJ = $(LIBFT_SRC:%.c=obj/%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft

# Create the obj directory and its subdirectories
OBJ_DIR = obj
$(shell mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/testing $(OBJ_DIR)/libft)

# The default target: compile everything
all: $(NAME)

# Link object files and create the executable
$(NAME): $(OBJ) $(TEST_OBJ) $(LIBFT_OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) $(TEST_OBJ) $(LIBFT_OBJ) -o $(NAME) -L$(LIBFT) -lft

# Rule to compile .c files to .o files in the obj directory
obj/%.o: %.c
	$(CC) $(CFLAGS) -I./include -I$(LIBFT)/include -c $< -o $@

# Clean the object files in the obj directory
clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ) $(TEST_OBJ) $(LIBFT_OBJ)

# Clean object files and the executable
fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
