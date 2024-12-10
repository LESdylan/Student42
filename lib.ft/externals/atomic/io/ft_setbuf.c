/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:25:47 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:25:49 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void setbuf(FILE *stream, char *buffer) {
    if (stream == NULL) {
        return;
    }
    
    // If the user provides a buffer, we set it
    stream->buffer = buffer;
    
    // If buffer is NULL, set unbuffered mode
    if (buffer == NULL) {
        stream->mode = _IONBF;  // No buffering
    } else {
        stream->mode = _IOFBF;  // Full buffering
    }
}
