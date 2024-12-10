/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:52:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strncat_s(char *dest, size_t dest_size, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    if (dest_len + src_len + 1 > dest_size || n > src_len) {
        return -1;  // Not enough space in destination buffer or invalid length
    }

    strncat(dest, src, n);
    return 0;
}

// Test function
int main() {
    char dest[50] = "Hello, ";
    const char *src = "World!";
    if (ft_strncat_s(dest, sizeof(dest), src, 3) == 0) {
        printf("Result: %s\n", dest);
    } else {
        printf("Error: Buffer overflow or invalid length\n");
    }
    return 0;
}
