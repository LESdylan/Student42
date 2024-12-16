/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:03:59 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 15:04:01 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s) + 1;
    char *dup = malloc(len);
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    return dup;
}
