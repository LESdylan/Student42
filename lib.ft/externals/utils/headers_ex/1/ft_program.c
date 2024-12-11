/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:05:14 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:05:17 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"

void ft_putstr(char *str) {
    while (*str)
        write(1, str++, 1);
}

t_bool ft_is_even(int nbr) {
    return (EVEN(nbr)) ? TRUE : FALSE;
}

int main(int argc, char **argv) {
    (void)argv; // Ignore the argv as per the instructions

    if (ft_is_even(argc - 1) == TRUE) // Check if the number of arguments (excluding the program name) is even
        ft_putstr(EVEN_MSG);
    else
        ft_putstr(ODD_MSG);

    return (SUCCESS); // Return 0 indicating successful execution
}
