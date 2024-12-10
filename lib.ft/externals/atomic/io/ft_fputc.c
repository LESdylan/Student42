/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:04 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:28:06 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int fputc(int ch, FILE *stream) {
    ssize_t bytes_written = write(stream->fd, &ch, 1);
    
    if (bytes_written == 1) {
        return ch;  // Return the character written
    }
    
    return EOF;  // Return EOF on error
}
