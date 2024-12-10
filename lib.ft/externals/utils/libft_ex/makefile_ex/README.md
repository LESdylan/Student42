Explanation of the Rules:
Variables:

CC = gcc: Defines the compiler to be used (gcc).
CFLAGS = -Wall -Wextra -Werror: Sets the compilation flags for warnings and errors.
SRC_DIR = srcs: Specifies the directory for source files.
INC_DIR = includes: Specifies the directory for header files.
SRC_FILES: Lists the source files in the srcs directory.
OBJ_FILES: Converts .c files to .o files for object files.
LIB_NAME = libft.a: Defines the name of the static library.
Default Rule (all):

The all rule builds the static library libft.a. Running make will automatically call this rule because it's the first rule in the Makefile.
Creating the Static Library (libft.a):

The $(LIB_NAME) target depends on the object files ($(OBJ_FILES)).
The ar rcs command is used to create the static library (libft.a) from the object files.
Cleaning Object Files (clean):

The clean rule removes the object files (.o), but does not remove the library itself.
Full Clean (fclean):

The fclean rule removes both the object files and the static library (libft.a).
Rebuild the Library (re):

The re rule calls fclean to remove all generated files, and then calls all to rebuild the library from scratch.
Compilation of .c to .o Files:

The %.o: %.c rule tells Make how to compile .c files into .o object files. It uses the gcc compiler with the specified flags and includes the includes directory for header files.
@echo "Compiling $<" prints the compilation message (the $< is the current .c file being compiled).
$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@ compiles the .c file into a .o object file.
.PHONY:

The .PHONY directive ensures that make treats the all, clean, fclean, and re rules as "phony" (i.e., they are not actual files but instead special commands).
