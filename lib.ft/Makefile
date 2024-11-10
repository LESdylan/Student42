CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIRS = ctype list string memory io
OBJ_DIR = obj

SRC = $(wildcard $(addprefix $(SRC_DIRS)/, *.c))
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Binaire final
TARGET = libft.a

# Cible par défaut
all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)/$$(dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

