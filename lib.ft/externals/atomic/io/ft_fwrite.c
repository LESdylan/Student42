/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:24:40 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:24:44 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream) {
    if (stream == NULL || ptr == NULL) {
        return 0;  // Invalid arguments
    }

    size_t total_bytes = size * count;
    ssize_t bytes_written = write(stream->fd, ptr, total_bytes);
    
    return (bytes_written > 0) ? bytes_written / size : 0;
}
