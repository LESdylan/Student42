# Libft - 42 School Project

## Introduction

Libft is a custom C library built as part of the curriculum at [42 School](https://www.42madrid.com/). This project aims to recreate a subset of standard C library functions and utility functions that are often used in larger projects. By implementing these functions, we gain a deeper understanding of low-level programming, memory management, and the inner workings of commonly used C functions.

This project lays the foundation for future projects by creating a personal C library that can be reused throughout the program.

## Overview

Libft consists of a variety of functions grouped by their purpose:

1. **Memory Functions**
These functions are used to manipulate blocks of memory, allowing operations like copying, moving, or setting values in memory.

- `memset`: Fill memory with a constant byte.
- `bzero`: Set all bytes in a block of memory to zero.
- `memcpy`: Copy memory from one location to another.
- `memccpy`: Copy memory until a specific character is found.
- `memmove`: Copy memory between potentially overlapping memory blocks.
- `memchr`: Find the first occurrence of a character in a memory block.
`memcmp`: Compare two blocks of memory.

2. **String Functions**
These functions allow manipulation and examination of C-style strings (null-terminated arrays of characters).

- `strlen`: Calculate the length of a string.
- `strchr`: Locate the first occurrence of a character in a string.
- `strrchr`: Locate the last occurrence of a character in a string.
- `strncmp`: Compare two strings up to a specified number of characters.
- `strlcpy`: Copy a string to a buffer, ensuring it is null-terminated.
- `strlcat`: Concatenate two strings, ensuring the result fits within a buffer.

3. **Character Checking Functions**
These functions check if a character meets certain conditions, such as being alphabetic or numeric.

- `isalpha`: Check if a character is an alphabetic letter.
- `isdigit`: Check if a character is a digit.
- `isalnum`: Check if a character is alphanumeric.
- `isascii`: Check if a character is an ASCII character.
- `isprint`: Check if a character is printable.
- `toupper`: Convert a lowercase character to uppercase.
- `tolower`: Convert an uppercase character to lowercase.

4. **Conversion Functions**
These functions are used to convert strings to other data types.

- `atoi`: Convert a string to an integer.

5. **The Static Library (libft.a)**
After implementing all the functions, they are compiled and archived into a static library file called libft.a. This library can be linked with future C projects to reuse the custom functions.

## How to Use
To use the **Libft** library in your projects, here are the steps:

**Clone the repository**

```bash
git clone https://github.com/Dles/libft.git
```
```bash
#navigate to the directory
cd libft
#compile the library
make
#Include Libft in your projects: You can link the libft.a library when compiling your projects. For example:
gcc main.c -L. -lft -o my_program
```

## Project Requirements
- No external libraries or functions are allowed.
- Functions should handle invalid input properly.
- Memory-related functions must avoid buffer overflows or segmentation faults.

## Conclusion
By completing this project, I've gained hands-on experience with fundamental C functions and low-level memory manipulation. Libft provides a solid foundation for future projects, allowing me to better understand how the standard C library works and preparing me for more advanced projects at 42 School.

Feel free to explore and use my custom library in your own C projects!

You can modify the link to your GitHub repository and adjust the wording as needed. This README.md format provides a structured, clear explanation of your Libft project, highlighting both its purpose and the functions it contains.
