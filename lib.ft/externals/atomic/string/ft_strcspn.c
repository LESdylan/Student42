/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:52:01 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strcspn(const char *s1, const char *s2) {
    size_t len = 0;
    while (s1[len]) {
        const char *temp = s2;
        while (*temp) {
            if (s1[len] == *temp) {
                return len;
            }
            temp++;
        }
        len++;
    }
    return len;
}

// Test function
int main() {
    const char *s1 = "Hello, World!";
    const char *s2 = " ,!";
    printf("Length before any match: %zu\n", ft_strcspn(s1, s2));
    return 0;
}
