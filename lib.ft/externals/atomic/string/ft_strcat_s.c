/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:45:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:45:50 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strcat_s(char *dest, size_t dest_size, const char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    if (dest_len + src_len + 1 > dest_size) {
        return -1;  // Not enough space
    }

    strcat(dest, src);
    return 0;
}

// Test function
#include <stdio.h>
int main() {
    char dest[20] = "Hello";
    const char *src = " World!";
    
    if (ft_strcat_s(dest, sizeof(dest), src) == 0) {
        printf("Concatenated string: %s\n", dest);
    } else {
        printf("Buffer overflow error\n");
    }
    return 0;
}
