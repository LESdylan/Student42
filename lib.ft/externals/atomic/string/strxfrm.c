/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strxfrm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:54:41 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:54:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strxfrm(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while (i < n - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (n > 0) {
        dest[i] = '\0';  // Null-terminate the destination string
    }
    return i;  // Return the length of the transformed string
}

// Test function
int main() {
    const char *str = "Hello, World!";
    char dest[50];
    size_t length = ft_strxfrm(dest, str, sizeof(dest));

    printf("Transformed string: %s\n", dest);
    printf("Length: %zu\n", length);
    return 0;
}
