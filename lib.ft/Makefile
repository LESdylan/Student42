# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g # Ajout de -g pour les symboles de débogage
LDFLAGS = -lm # Lien avec la bibliothèque mathématique

# Source directories and object directory
SRC_DIRS = ctype list string memory io
OBJ_DIR = obj
MSG = "updated";
# Automatically detect all source files
SRC = $(wildcard $(addprefix $(SRC_DIRS)/, *.c)) $(wildcard $(addprefix $(SRC_DIRS)/, *.c))
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Final binary target
TARGET = myprogram

# Default target to build the program
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET) # Lier les objets et la lib math

# Rule to compile each source file
$(OBJ_DIR)/%.o: $(SRC_DIRS)/%.c
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
	# Ensure compile.sh compiles the C file correctly and links the math library
	/home/dyl-syzygy/Student42/lib.ft/scripts/compile.sh $(SRC_PATH)

# Clean the exp directory
delexp:
	rm -rf /home/dyl-syzygy/Student42/lib.ft/exp/*
	echo "Exp directory cleaned."

# Run the script with the proper parameters (use the compiled file or executable)
run: compile
	# Assuming compile.sh creates a file in /home/dyl-syzygy/Student42/lib.ft/exp/
	/home/dyl-syzygy/Student42/lib.ft/exp/$(SRC_FILENAME)

# Push changes to the git repository
push:
	git add . ; git commit -m "$(MSG)"; git push

# Debugging: Start GDB with the target executable
debug: $(TARGET)
	@echo "Starting GDB..."
	@gdb ./$(TARGET)

# Help target to show available commands
help:
	@echo "Usage: make [target]"
	@echo ""
	@echo " \e[34;4mAvailable Targets:\e[0m	| \e[34;4mInstruction\e[0m"
	@echo "			|		"
	@echo  " \e[32mall\e[0m            	| \e[33mBuild the program (default target)"
	@echo  " \e[31mclean\e[0m      		| \e[33mRemove object files"
	@echo  " \e[31mdelexp\e[0m      		| \e[33mClean the exp directory"
	@echo  " \e[31mfclean\e[0m      		| \e[33mRemove object files and the program"
	@echo  " \e[31mre\e[0m      		| \e[33mRebuild the program (clean and all)"
	@echo  " \e[35mcompile\e[0m      		| \e[33mCompile a specific source file"
	@echo  " \e[35mrun\e[0m      		| \e[33mRun a custom script"
	@echo  " \e[36mhelp\e[0m      		| \e[33mDisplay this help message"
	@echo  " \e[36mpush\e[0m			| \e[33mPush to git repository"
	@echo ""
