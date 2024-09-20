/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan-soul <dylan-soul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:06 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/09/21 00:19:58 by dylan-soul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize > 0)
	{
		while (*src && --dstsize)
			*(dest + len++) = *src++;
		*(dest + len) = '\0';
	}
	while (*src++)
		len++;
	return (len);
}
