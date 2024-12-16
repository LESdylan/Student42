/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:19:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:20:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*last;
	char		find;
	size_t		i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (NULL);
}

//!improved version
/*
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	find;

	last = NULL;
	find = (char)c;

	while (*s)
	{
		if (*s == find)
			last = (char *)s;
		s++;
	}
	// Check for the null terminator if 'c' is '\0'
	if (find == '\0')
		return ((char *)s);
	return (last);
}

*/