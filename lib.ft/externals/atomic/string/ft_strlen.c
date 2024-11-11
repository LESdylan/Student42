/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:08 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/11/12 00:03:45 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	ft_strlen(const char *s) 
{ 
	int i = 0; 
	while (*(s + i++) != '\0'); 
	return (i-1); 
}

int main()
{
	printf("\n%d\n",ft_strlen("hello"));
}
