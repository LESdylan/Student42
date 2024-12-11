/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:51:34 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:51:35 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, const char *src) {
    char *dest_ptr = dest;

    // Move to the end of dest string
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    // Copy characters from src to dest
    while (*src != '\0') {
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
    const char *src = "World!";
    printf("Result: %s\n", ft_strcat(dest, src));
    return 0;
}
