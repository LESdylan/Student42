#!/bin/bash

# Validate input: Ensure it is numeric
if ! [[ $1 =~ ^[0-9]+$ ]]; then
    echo "Error: Please provide a numeric input."
    exit 1
fi

# Initialize an empty result string
result=""

# Check divisibility and append corresponding string
if [[ $(($1 % 3)) -eq 0 ]]; then
    result+="Pling"
fi
if [[ $(($1 % 5)) -eq 0 ]]; then
    result+="Plang"
fi
if [[ $(($1 % 7)) -eq 0 ]]; then
    result+="Plong"
fi

# Output the result or the number if no matches
if [[ -z $result ]]; then
    echo "$1"
else
    echo "$result"
fi
