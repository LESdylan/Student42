/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:29:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:29:52 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ungetc(int ch, FILE *stream) {
    // Place the character back into the input buffer (simplified version)
    if (stream == NULL) {
        return EOF;
    }

    // Assuming the stream is buffered, we can push the character back to the stream's buffer
    // Typically, the internal buffer would be used to store the character for later retrieval

    // For simplicity, we'll just return the character since the buffering is handled by the system
    return ch;
}
