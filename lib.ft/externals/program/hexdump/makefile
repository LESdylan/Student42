# Makefile for ft_hexdump

NAME = ft_hexdump
SRC = ft_hexdump.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
