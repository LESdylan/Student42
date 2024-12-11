/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:24:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:24:37 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

long long atoll(const char *str) {
    long long result = 0;
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

    // Convert digits to long long
    while (isdigit((unsigned char)*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

// Test function
int main() {
    const char *test_str = "  +987654321";
    printf("atoll('%s') = %lld\n", test_str, atoll(test_str));
    return 0;
}
