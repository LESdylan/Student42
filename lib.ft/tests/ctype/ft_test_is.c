/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:07:30 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/11/10 18:14:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/dylan-soul/student42/lib.ft/externals/include/mylib.h" // Ensure this path is correct
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);

// Function pointer type
typedef int (func)(int);

// Function to check assertions
int ck_assert_int_eq(func f, int x, int expected) {
    return (f(x) == expected) ? 1 : 0;
}

// Function to generate and test characters
void run_tests() {
    for (int i = 0; i < 256; i++) {
        int expected_alpha = (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z');
        int expected_digit = (i >= '0' && i <= '9');
        int expected_alnum = expected_alpha || expected_digit;
        int expected_print = (i >= 32 && i <= 126);
        int expected_ascii = (i >= 0 && i <= 127);

        printf("Testing character: '%c' (ASCII: %d)\n", (char)i, i);
        printf("ft_isalpha: %d (expected: %d) => %d\n", 
            ck_assert_int_eq(ft_isalpha, i, expected_alpha), expected_alpha);
        printf("ft_isdigit: %d (expected: %d) => %d\n", 
            ck_assert_int_eq(ft_isdigit, i, expected_digit), expected_digit);
        printf("ft_isalnum: %d (expected: %d) => %d\n", 
            ck_assert_int_eq(ft_isalnum, i, expected_alnum), expected_alnum);
        printf("ft_isprint: %d (expected: %d) => %d\n", 
            ck_assert_int_eq(ft_isprint, i, expected_print), expected_print);
        printf("ft_isascii: %d (expected: %d) => %d\n", 
            ck_assert_int_eq(ft_isascii, i, expected_ascii), expected_ascii);
        printf("\n");
    }
}

int main(void) {
    run_tests(); // Run the tests
    return 0;
}
