/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:13:57 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:26:28 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int value, char *str, int base) {
    if (base < 2 || base > 36) {
        *str = '\0'; // Invalid base
        return;
    }

    char *ptr = str;
    char *end = str;
    int sign = (value < 0 && base == 10) ? -1 : 1;

    // Handle the value and create the string in reverse
    value = (sign < 0) ? -value : value;

    do {
        int digit = value % base;
        *end++ = (digit > 9) ? (digit - 10 + 'a') : (digit + '0');
        value /= base;
    } while (value > 0);

    if (sign < 0) {
        *end++ = '-';
    }

    *end = '\0';

    // Reverse the string
    for (char *start = str; start < end - 1; start++, end--) {
        char tmp = *start;
        *start = *(end - 1);
        *(end - 1) = tmp;
    }
}

// Test function
int main() {
    char buffer[20];
    itoa(12345, buffer, 10);
    printf("itoa(12345) = %s\n", buffer); // Should print "12345"
    itoa(-12345, buffer, 10);
    printf("itoa(-12345) = %s\n", buffer); // Should print "-12345"
    itoa(255, buffer, 16);
    printf("itoa(255, 16) = %s\n", buffer); // Should print "ff"
    return 0;
}
