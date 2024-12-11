#!/usr/bin/env bash

i=0
count=0

# Ensure the script gets exactly two arguments
if [[ $# -ne 2 ]]; then
  echo "Please provide exactly two strings to compare."
  exit 1
fi

# Check if any string is empty
if [[ -z $1 || -z $2 ]]; then
    echo "Either one or both strings are empty."
    exit 1
fi

# Check if strings are of the same length
if [[ ${#1} -ne ${#2} ]]; then
    echo "Please provide exactly two strings of the same length."
    exit 1
fi

# Compare each character of both strings
while [[ $i -lt ${#1} && $i -lt ${#2} ]]; do
  if [[ ${1:$i:1} != ${2:$i:1} ]]; then
    ((count++))  # Increment count when characters differ
  fi
  ((i++))
done

# Output the Hamming distance
echo "$count"
