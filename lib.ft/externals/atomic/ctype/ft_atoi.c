/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:25 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/11/26 16:49:52 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <math.h>
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

int atoi_recursive(const char *str) {
    // Cas de base : chaîne vide ou fin de chaîne
    if (*str == '\0') {
        return 0;
    }

    // Appel récursif pour le reste de la chaîne
    int result = atoi_recursive(str + 1);

    // Convertit le caractère actuel en chiffre et ajuste son poids
    return (*str - '0') * pow(10, strlen(str) - 1) + result;
}


int main(void)
{
	printf("%d\n",ft_atoi("1245"));
	printf("%d\n",atoi_recursive("1245455"));
	return 0;
}