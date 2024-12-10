/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:27:47 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:27:49 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int fgetc(FILE *stream) {
    unsigned char ch;
    ssize_t bytes_read = read(stream->fd, &ch, 1);
    
    if (bytes_read > 0) {
        return (int)ch;  // Return the character as an integer
    }
    
    return EOF;  // Return EOF on error or end-of-file
}
