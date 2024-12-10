/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:52 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:41:16 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n) {
    if (!dest || !src) return NULL;

    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while (n--) {
        *d++ = *s++;
    }

    return dest;
}
