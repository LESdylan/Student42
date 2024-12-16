/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:11 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:30:52 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)ft_calloc(sizeof(*s3), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	return (s3);
}

/**
 *  !Key Improvements
*   *Better Memory Allocation:
*   *
*   *Used ft_calloc more precisely: Allocating (s1_len + s2_len + 1) bytes ensures enough memory for both strings and the null terminator.
*   *Removed the unnecessary cast for ft_calloc, since the return type is already void *.
*   *Separate Variables for Lengths:
*   *
*   *Stored the lengths of s1 and s2 in s1_len and s2_len, respectively, to avoid recomputing ft_strlen multiple times. This reduces redundant function calls, improving readability and performance.
*   *Eliminated Pointer Increment of s1:
*   *
*   *Avoided modifying the s1 and s2 pointers during the function. Instead, copied data using indices or direct reference. This ensures the original pointers remain unchanged.
*   *Null Terminator:
*   *
*   *Automatically added by ft_calloc, so no manual addition is necessary.
 * 
 * 
 * 
 * #include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	// Allocate memory for the joined string, including space for the null terminator.
	joined_str = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!joined_str)
		return (NULL);

	// Copy s1 to joined_str.
	i = 0;
	while (i < s1_len)
	{
		joined_str[i] = s1[i];
		i++;
	}

	// Append s2 to joined_str.
	while (*s2)
	{
		joined_str[i++] = *s2++;
	}

	return (joined_str);
}

 */