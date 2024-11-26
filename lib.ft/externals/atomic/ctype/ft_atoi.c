/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:25 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/11/26 14:06:56 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//TODO: maybe verify if the string contain alphabetic character so the algorithm can ignore it
int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign_count;

	res = 0;
	sign_count = 0;
	while (*nptr == '\f'
		|| *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == 32
		|| *nptr == '\n')
		nptr++;
	while (*nptr == '+' || *nptr == '-' )
	{
		if (*nptr == '-')
			sign_count++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign_count % 2 == 1)
		res *= -1;
	return (res);
}

int	ft_recursive_atoi(char *str)
{
	
}

int main(void)
{
	printf("%d\n",ft_atoi("1245"));
	printf("%d\n",ft_recusrive_atoi("1245"));
	return 0;
}