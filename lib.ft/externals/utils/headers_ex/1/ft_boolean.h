/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:04:40 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:04:41 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

// Define the boolean type
typedef enum {
    FALSE = 0,
    TRUE = 1
} t_bool;

// Define the SUCCESS value
# define SUCCESS 0

// Define macro to check if a number is even
# define EVEN(nbr) ((nbr) % 2 == 0)

// Define messages to display based on the even or odd check
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

// Define the standard return for main function when SUCCESS
# define SUCCESS 0

#endif
