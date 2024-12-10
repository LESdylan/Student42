/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:58:26 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 14:58:27 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// Function prototypes for the operations
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div_op(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

// Function to safely perform division
int safe_div(int a, int b) {
    if (b == 0) {
        printf("Stop : division by zero\n");
        return -1;  // Signal division by zero error
    }
    return div_op(a, b);
}

// Function to safely perform modulo
int safe_mod(int a, int b) {
    if (b == 0) {
        printf("Stop : modulo by zero\n");
        return -1;  // Signal modulo by zero error
    }
    return mod(a, b);
}

// Function to handle invalid input and convert string to integer
int convert_to_int(char *str) {
    char *endptr;
    long result = strtol(str, &endptr, 10);

    // Check if the conversion was successful
    if (*endptr != '\0' || result > INT_MAX || result < INT_MIN) {
        return 0; // Invalid conversion or out of range
    }
    return (int)result;
}

int main(int argc, char **argv) {
    // Check for invalid number of arguments
    if (argc != 4) {
        return 0; // Do nothing if there are not exactly three arguments
    }

    // Convert value1 and value2 to integers
    int value1 = convert_to_int(argv[1]);
    int value2 = convert_to_int(argv[3]);

    // If either value1 or value2 is invalid, print nothing and return
    if (value1 == 0 || value2 == 0) {
        return 0;
    }

    // Array of function pointers for operators
    int (*ops[5])(int, int) = {add, sub, mul, safe_div, safe_mod};
    char operators[] = {'+', '-', '*', '/', '%'};
    
    int i;
    for (i = 0; i < 5; i++) {
        if (argv[2][0] == operators[i]) {
            // Check if division or modulo by zero
            if ((i == 3 && value2 == 0) || (i == 4 && value2 == 0)) {
                return 0;
            }
            // Call the corresponding operation function and print the result
            printf("%d\n", ops[i](value1, value2));
            return 0;
        }
    }

    // If no valid operator is found, print 0
    printf("0\n");
    return 0;
}
