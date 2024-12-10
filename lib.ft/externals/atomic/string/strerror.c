/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:56:04 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define EINVAL 22   // Invalid argument
#define ENOMEM 12   // Out of memory
#define EPERM 1     // Operation not permitted
#define EIO 5       // Input/output error

const char *ft_strerror(int errnum) {
    // Return the corresponding error message for the given error number
    switch (errnum) {
        case EINVAL:
            return "Invalid argument";
        case ENOMEM:
            return "Out of memory";
        case EPERM:
            return "Operation not permitted";
        case EIO:
            return "Input/output error";
        default:
            return "Unknown error";
    }
}

// Test function
int main() {
    int err = ENOMEM;
    printf("Error %d: %s\n", err, ft_strerror(err));

    err = EPERM;
    printf("Error %d: %s\n", err, ft_strerror(err));

    err = 999; // Unknown error
    printf("Error %d: %s\n", err, ft_strerror(err));

    return 0;
}
