/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:52:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Test function
int main() {
    const char *str = "Hello, World!";
    printf("Length: %zu\n", ft_strlen(str));
    return 0;
}
