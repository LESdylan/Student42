/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:21:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*needle)
		return ((char *)haystack);
	pos = 0;
	while (haystack[pos] && (size_t)pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[pos + i] == needle[i]
				&& (size_t)(pos + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[pos]);
		}
		pos++;
	}
	return (NULL);
}

//!BETTER CLARIFICATION AND IMPROVED
/*
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_pos;
	size_t	n_pos;

	// If needle is an empty string, return haystack
	if (!*needle)
		return ((char *)haystack);

	h_pos = 0;
	while (haystack[h_pos] && h_pos < len)
	{
		// Check if the first character matches
		if (haystack[h_pos] == needle[0])
		{
			n_pos = 0;
			// Compare the rest of the needle
			while (needle[n_pos] && haystack[h_pos + n_pos] == needle[n_pos]
				&& (h_pos + n_pos) < len)
				n_pos++;
			// If we reached the end of the needle, return the starting position
			if (!needle[n_pos])
				return ((char *)&haystack[h_pos]);
		}
		h_pos++;
	}
	return (NULL);
}
*/