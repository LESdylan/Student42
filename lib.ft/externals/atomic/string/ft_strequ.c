/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:22:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:23:07 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // for NULL

int ft_strequ(char const *s1, char const *s2)
{
    // If either of the strings is NULL, they are not identical
    if (!s1 || !s2)
        return 0;

    // Compare the strings character by character
    while (*s1 && *s2)
    {
        // If characters are different, return 0
        if (*s1 != *s2)
            return 0;
        
        // Move to the next characters
        s1++;
        s2++;
    }

    // If both strings end at the same time (both NULL), they are identical
    // If one string ends before the other, they are not identical
    return *s1 == *s2 ? 1 : 0;
}

#include <stdio.h>

int main()
{
    // Test identical strings
    char str1[] = "hello";
    char str2[] = "hello";
    char str3[] = "world";

    // Test different strings
    printf("Test 1: %d\n", ft_strequ(str1, str2));  // Should print 1
    printf("Test 2: %d\n", ft_strequ(str1, str3));  // Should print 0
    printf("Test 3: %d\n", ft_strequ(str1, NULL));  // Should print 0
    printf("Test 4: %d\n", ft_strequ(NULL, str3));  // Should print 0
    printf("Test 5: %d\n", ft_strequ(NULL, NULL));  // Should print 0

    return 0;
}
