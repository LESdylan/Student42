/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan-soul <dylan-soul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:25 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/09/19 16:27:06 by dylan-soul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
