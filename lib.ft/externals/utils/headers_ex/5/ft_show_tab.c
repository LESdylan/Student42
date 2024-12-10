/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:18:30 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:18:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str++, 1);
    }
}

void ft_putnbr(int n)
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    
    while (par[i].str != 0)  // Check until you reach the end of the array
    {
        ft_putstr(par[i].str);  // Print the string
        write(1, "\n", 1);       // Newline after the string
        
        ft_putnbr(par[i].size);  // Print the size
        write(1, "\n", 1);       // Newline after the size
        
        ft_putstr(par[i].copy);  // Print the copy
        write(1, "\n", 1);       // Newline after the copy
        
        i++;  // Move to the next structure
    }
}
