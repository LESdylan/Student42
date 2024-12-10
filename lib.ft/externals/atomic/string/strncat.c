/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:55:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:55:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, const char *src, size_t n) {
    char *dest_ptr = dest;

    // Move to the end of dest string
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    // Append up to 'n' characters from src to dest
    while (n-- && *src != '\0') {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }

    *dest_ptr = '\0'; // Null-terminate the concatenated string
    return dest;
}

// Test function
int main() {
    char dest[50] = "Hello, ";
    const char *src = "World! This is a test.";
    printf("Result: %s\n", ft_strncat(dest, src, 6));  // Appending only "World!"
    return 0;
}
