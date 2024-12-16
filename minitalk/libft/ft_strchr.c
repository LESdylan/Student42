/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:34:05 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:34:37 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (NULL);
}

/**
 *  !Key Improvements:
*   *Pointer-based Iteration:
*   *
*   *Using while (*s) allows you to directly iterate over the string with the pointer, eliminating the need for an index variable.
*   *Simplified Code:
*   *
*   *Removed the redundant i and directly checked the characters using the pointer.
*   *Consistency:
*   *
*   *The check at the end of the function (if (*s == find)) is still needed to handle the edge case where the character is the null terminator (\0).
*   *Explanation of the Function:
*   *Purpose:
*   *
*   *This function searches for the first occurrence of the character c in the string s. It returns a pointer to that character or NULL if the character is not found.
*   *Input:
*   *
*   *s: The string to be searched.
*   *c: The character to search for, which is cast to char (but still passed as int to handle extended character sets).
*   *Output:
*   *
*   *A pointer to the first occurrence of c in s, or NULL if the character is not found.
*   *
 * 
 * #include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    char	find;

    find = (char)c;
    while (*s)  // Loop through the string
    {
        if (*s == find)
            return ((char *)s);  // Return pointer to the matching character
        s++;
    }
    if (*s == find)  // Check if the null terminator is the match
        return ((char *)s);

    return (NULL);  // Return NULL if no match is found
}

 */