# Name of the library
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = ft_strlen.c ft_strchr.c ft_strdup.c
OBJ = $(SRC:.c=.o)

# All targets
all: $(NAME)

# Create the library from the object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Clean the object files
clean:
	rm -f $(OBJ)

# Clean the object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library

.PHONY: all clean fclean re
