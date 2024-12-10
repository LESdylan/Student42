/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:11:28 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:11:30 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_stock_str.h"

// Function to display the array of structures
void ft_show_tab(t_stock_str *tab)
{
    int i = 0;
    while (tab[i].str != 0) // Loop until we encounter the last NULL element
    {
        printf("String: %s\n", tab[i].str);
        printf("Size: %d\n", tab[i].size);
        printf("Copy: %s\n", tab[i].copy);
        i++;
    }
}
