#!/bin/bash

# Directories
SRC_DIR="src"
OBJ_DIR="obj"
LIB_DIR="lib"
INCLUDE_DIR="include"
LIBRARY="$LIB_DIR/libft.a"

# Compiler and flags
CC="gcc"
CFLAGS="-Wall -Wextra -Werror"

# Ensure necessary directories exist
mkdir -p $OBJ_DIR $LIB_DIR

find_sources() {
  find $SRC_DIR -name "*.c" -not -name "test.c"
}

compile_sources() {
  echo "Compiling source files..."
  for src_file in $(find_sources); do
    obj_file="$OBJ_DIR/$(basename ${src_file%.c}.o)"
    echo "Compiling $src_file to $obj_file"
    $CC $CFLAGS -I$INCLUDE_DIR -c $src_file -o $obj_file
  done
}

create_library() {
  echo "Creating/updating library: $LIBRARY"
  ar rcs $LIBRARY $OBJ_DIR/*.o
}

clean_objects() {
  echo "Cleaning object directory..."
  rm -rf $OBJ_DIR/*.o
}

build_test() {
  echo "Compiling test program..."
  $CC $CFLAGS -I$INCLUDE_DIR $SRC_DIR/test.c -L$LIB_DIR -lft -o test_program
}

build_library() {
  clean_objects
  compile_sources
  create_library
  build_test
  echo "Library and test program built successfully!"
}

build_library
