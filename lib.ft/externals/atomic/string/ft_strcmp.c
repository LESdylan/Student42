/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:51:38 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:51:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// Test function
int main() {
    const char *str1 = "apple";
    const char *str2 = "banana";
    int result = ft_strcmp(str1, str2);
    if (result < 0) {
        printf("\"%s\" is less than \"%s\"\n", str1, str2);
    } else if (result > 0) {
        printf("\"%s\" is greater than \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" is equal to \"%s\"\n", str1, str2);
    }
    return 0;
}
