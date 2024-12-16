/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:39:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:41:24 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	if (!ptr)
	{
		ft_putstr_pf("(nil)", counter);
		return;
	}
	
	ptr_address = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);  // Print the "0x" prefix to indicate hexadecimal
	str = ft_atoi_base(ptr_address, HEX_LOW_BASE);  // Convert the address to a hex string
	ft_putstr_pf(str, counter);  // Print the hex string representation of the pointer
	free(str);  // Free the allocated memory for the string
}

/*
void	ft_putptr_pf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);
	str = ft_atoi_base(ptr_address, HEX_LOW_BASE);
	ft_putstr_pf(str, counter);
	free(str);
}
 */
