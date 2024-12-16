/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:38:50 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:39:29 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_pf(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str, counter);
		str++;
	}
}

/**
 * #include "libft.h"

void	ft_putstr_pf(char *str, size_t *counter)
{
	// Handle the case where the string is NULL
	if (!str)
		str = "(null)";
	
	// Print each character of the string
	while (*str)
	{
		ft_putchar_pf(*str, counter);  // Print the character and update the counter
		str++;
	}
}

 */