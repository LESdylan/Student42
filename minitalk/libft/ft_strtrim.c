/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:18:38 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:19:46 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

/*
char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;

    if (!s1 || !set)
        return (NULL);

    start = 0;
    // Find the first character that is not in 'set'
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;

    // If the string only contains characters in 'set', return an empty string
    if (s1[start] == '\0')
        return (ft_calloc(1, sizeof(char)));

    end = ft_strlen(s1) - 1;
    // Find the last character that is not in 'set'
    while (end > start && ft_strchr(set, s1[end]))
        end--;

    // Return the substring from start to end (inclusive)
    return (ft_substr(s1, start, end - start + 1));
}
*/