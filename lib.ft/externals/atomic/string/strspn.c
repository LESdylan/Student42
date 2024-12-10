/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strspn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:53:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:53:04 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strspn(const char *s1, const char *s2) {
    size_t len = 0;
    while (s1[len]) {
        const char *temp = s2;
        int found = 0;
        while (*temp) {
            if (s1[len] == *temp) {
                found = 1;
                break;
            }
            temp++;
        }
        if (!found) {
            break;
        }
        len++;
    }
    return len;
}

// Test function
int main() {
    const char *s1 = "abc123";
    const char *s2 = "abc";
    printf("Length of initial segment: %zu\n", ft_strspn(s1, s2));
    return 0;
}
