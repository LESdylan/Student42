/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:54:30 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:54:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

long ft_strtol(const char *str, char **endptr, int base) {
    while (*str && isspace((unsigned char)*str)) {
        str++;  // Skip leading whitespace
    }

    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    long result = 0;
    while ((*str >= '0' && *str <= '9') || 
           (base > 10 && (*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F'))) {
        int value = (*str >= '0' && *str <= '9') ? *str - '0' : 
                    (*str >= 'a' && *str <= 'f') ? *str - 'a' + 10 : 
                    *str - 'A' + 10;

        if (value >= base) {
            break;
        }

        result = result * base + value;
        str++;
    }

    if (endptr) {
        *endptr = (char *)str;
    }

    return sign * result;
}

// Test function
int main() {
    const char *str = "  -123abc";
    char *endptr;
    long result = ft_strtol(str, &endptr, 16);
    printf("Converted number: %ld\n", result);
    printf("Remaining string: %s\n", endptr);
    return 0;
}