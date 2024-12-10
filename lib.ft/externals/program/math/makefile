CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = do-op.c
OBJ = $(SRC:.c=.o)
NAME = ft_do_op

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
