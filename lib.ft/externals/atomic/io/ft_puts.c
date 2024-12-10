/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:14 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:28:18 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int fputs(const char *str, FILE *stream) {
    size_t len = 0;
    
    // Calculate the length of the string
    while (str[len] != '\0') {
        len++;
    }
    
    ssize_t bytes_written = write(stream->fd, str, len);
    
    if (bytes_written == len) {
        return 0;  // Success
    }
    
    return EOF;  // Return EOF on error
}
