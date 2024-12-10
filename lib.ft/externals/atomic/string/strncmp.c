/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:52:50 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (n == (size_t)-1) ? 0 : *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Test function
int main() {
    const char *str1 = "apple";
    const char *str2 = "apricot";
    int result = ft_strncmp(str1, str2, 3);  // Compare first 3 characters
    if (result < 0) {
        printf("\"%s\" is less than \"%s\"\n", str1, str2);
    } else if (result > 0) {
        printf("\"%s\" is greater than \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" is equal to \"%s\"\n", str1, str2);
    }
    return 0;
}
