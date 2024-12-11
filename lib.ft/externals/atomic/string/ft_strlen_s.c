/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:18 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:55:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strlen_s(const char *str, size_t max_len) {
    size_t length = 0;

    // Iterate through the string until we either reach the end of the string or max_len
    while (str[length] != '\0' && length < max_len) {
        length++;
    }

    return length;
}

// Test function
int main() {
    const char *str = "Hello, World!";
    printf("Length: %zu\n", ft_strlen_s(str, 5));  // Should output 5 (not the full length)
    printf("Full length: %zu\n", ft_strlen_s(str, 100));  // Should output 13 (full length)
    return 0;
}
