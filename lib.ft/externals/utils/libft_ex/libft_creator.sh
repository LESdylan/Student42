#!/bin/bash

# Compile each C file into an object file
gcc -c ft_putchar.c
gcc -c ft_swap.c
gcc -c ft_putstr.c
gcc -c ft_strlen.c
gcc -c ft_strcmp.c

# Create the static library libft.a
ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Clean up object files after creating the library
rm -f *.o

echo "libft.a has been created successfully!"
