/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:51:44 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:51:48 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcpy_s(char *dest, size_t dest_size, const char *src) {
    size_t src_len = strlen(src);

    if (src_len >= dest_size) {
        return -1;  // Not enough space in destination buffer
    }

    // Copy the string
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the destination string
    return 0;
}

// Test function
int main() {
    char dest[20];
    const char *src = "Hello, World!";
    
    if (ft_strcpy_s(dest, sizeof(dest), src) == 0) {
        printf("Destination: %s\n", dest);
    } else {
        printf("Error: Buffer overflow\n");
    }
    
    return 0;
}
