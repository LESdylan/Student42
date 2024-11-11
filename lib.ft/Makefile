# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source directories and object directory
SRC_DIRS = ctype list string memory io
OBJ_DIR = obj

# Automatically detect all source files
SRC = $(wildcard $(addprefix $(SRC_DIRS)/, *.c))
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Final binary target
TARGET = libft.a

# Default target to build the library
all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) rcs $@ $^

# Rule to compile each source file
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)/$$(dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove object files
clean:
	rm -rf $(OBJ_DIR)

# Clean and remove the final binary
fclean: clean
	rm -f $(TARGET)

# Rebuild everything from scratch
re: fclean all

# Custom variable for the source path (absolute path to .c file)
SRC_PATH = /home/dyl-syzygy/Student42/lib.ft/externals/ctype/ft_isalpha.c

# Extract the filename without the path or extension
SRC_FILENAME = $(notdir $(basename $(SRC_PATH)))

# Run the script with parameters
compile:
	/home/dyl-syzygy/Student42/lib.ft/scripts/compile.sh $(SRC_PATH)

# Clean the exp directory
delexp:
	rm -rf /home/dyl-syzygy/Student42/lib.ft/exp/*
	echo "Exp directory cleaned."

# Run the script with the proper parameters
run: compile
	/home/dyl-syzygy/Student42/lib.ft/exp/$(SRC_FILENAME)
