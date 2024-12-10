/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:25:35 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:25:37 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int fflush(FILE *stream) {
    if (stream == NULL) {
        return EOF;  // Invalid stream
    }

    return fsync(stream->fd);  // Sync file descriptor to disk
}
