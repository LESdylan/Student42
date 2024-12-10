/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:25:09 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:25:13 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int fclose(FILE *stream) {
    if (stream == NULL) {
        return EOF;  // Invalid stream
    }

    int result = close(stream->fd);
    free(stream);
    
    return (result == 0) ? 0 : EOF;
}
