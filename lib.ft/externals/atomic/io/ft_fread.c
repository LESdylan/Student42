/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:24:11 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:24:14 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t fread(void *ptr, size_t size, size_t count, FILE *stream) {
    if (stream == NULL || ptr == NULL) {
        return 0;  // Invalid arguments
    }

    size_t total_bytes = size * count;
    ssize_t bytes_read = read(stream->fd, ptr, total_bytes);
    
    return (bytes_read > 0) ? bytes_read / size : 0;
}
