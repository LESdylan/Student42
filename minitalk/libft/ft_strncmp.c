/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:22:04 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:24:09 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * !For clarity and robustness
 * Clarity in the while loop:
 * * Explicitly condition the loop on i < n && s1[i] && s2[i] to make it clear why we exit the loop early
 * * The improved loop ensures that we do not access beyond the bounds of either string or n
 * * Early exit for mismatched characters:
 * * If s1[i] and s2[i] differ, the function immediately returns the difference, simplifying logic.
 * * Edge case handling: 
 * * After the loop, the case where i < n is explicitly handled to account for unequal string lengths (e.g., one string ends with a null terminator while the other continues).
 * * Readability and maintainability:
 * * Structured the code to improve its flow and added comments for better understanding.

 * #include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	// If no comparison is needed, return 0
	if (n == 0)
		return (0);

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}

	// Handle cases where strings are of unequal length
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);

	return (0);
}

 */