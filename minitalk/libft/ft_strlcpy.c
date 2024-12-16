/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:26:53 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:27:42 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

/**
 *  !Key Improvements
*   * Null Pointer Check:
*   * 
*   * Added if (!dest || !src) to handle cases where dest or src is NULL.
*   * While the standard strlcpy does not perform this check, it's a good defensive programming practice for custom implementations.
*   * Simplified Logic:
*   * 
*   * The original srclen calculation is replaced by directly using ft_strlen(src) in the return statement.
*   * This reduces redundancy by computing the source string's length only when it’s actually needed.
*   * Adhering to Standard Behavior:
*   * 
*   * The function ensures the destination is null-terminated if dstsize is greater than 0, even when the source string is empty.


 * 
 * 
 * #include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dest || !src)
		return (0); // Handle null pointers gracefully.
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i < (dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0'; // Null-terminate the destination.
	}
	return (ft_strlen(src)); // Return the full length of the source string.
}

 */