/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:23:21 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:23:25 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // for NULL

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    // If either string is NULL, or n is zero, they are not identical
    if (!s1 || !s2 || n == 0)
        return 1;  // If n is 0, we consider them equal (since no comparison is done)

    // Compare the strings character by character, up to n characters or until null terminator is reached
    while (n-- && *s1 && *s2)
    {
        // If characters are different, return 0
        if (*s1 != *s2)
            return 0;
        
        // Move to the next characters
        s1++;
        s2++;
    }

    // If we have compared n characters or reached null terminator for both strings,
    // they are equal up to n characters or null terminator
    return 1;
}
