/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:24:18 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:24:28 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

long atol(const char *str) {
    long result = 0;
    int sign = 1;

    // Skip leading whitespace
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Check for optional sign
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convert digits to long
    while (isdigit((unsigned char)*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

// Test function
int main() {
    const char *test_str = "  -12345";
    printf("atol('%s') = %ld\n", test_str, atol(test_str));
    return 0;
}
