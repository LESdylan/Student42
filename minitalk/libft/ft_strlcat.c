/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:28:04 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:28:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	j = dst_length;
	i = 0;
	if (dst_length < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && dst_length + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	if (dst_length >= dstsize)
		dst_length = dstsize;
	return (dst_length + src_length);
}


/**
 *  !Key Improvements
*   *Null Pointer Check:
*   *
*   *Added if (!dst || !src) to handle cases where dst or src is NULL.
*   *While the standard strlcat does not explicitly handle this, it’s a good practice in custom implementations.
*   *Condition Simplification:
*   *
*   *Directly check if dstsize <= dst_len and handle it as a special case early. This avoids unnecessary computations and edge-case checks later.
*   *Proper Null-Termination:
*   *
*   *Ensure the resulting string in dst is always null-terminated when dstsize > dst_len.
*   *Readability:
*   *
*   *Improved clarity by using descriptive variable names (dst_len, src_len) and reducing nested logic.

 * 
 * #include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0); // Handle null pointers gracefully.
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	// If `dstsize` is 0 or less than the length of `dst`, return `dstsize + src_len`.
	if (dstsize <= dst_len)
		return (dstsize + src_len);

	i = 0;
	while (src[i] && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0'; // Null-terminate the resulting string.

	return (dst_len + src_len);
}

 */