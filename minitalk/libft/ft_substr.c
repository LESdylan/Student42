/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:17:39 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:18:14 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t str_len;

    if (!s)
        return (NULL);

    str_len = ft_strlen(s);
    
    // If start is greater than the string length, return an empty string
    if (start >= str_len)
        return (ft_calloc(1, sizeof(char)));

    // Adjust len if it's too large
    if (str_len - start < len)
        len = str_len - start;

    // Allocate memory for the substring
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);

    // Copy the characters from the original string to the substring
    ft_strlcpy(str, s + start, len + 1);

    return (str);
}

*/