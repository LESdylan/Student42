/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:09:10 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:14:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

// Structure definition
typedef struct s_stock_str
{
    int size;
    char *str;
    char *copy;
} t_stock_str;

// Function declarations
t_stock_str *ft_strs_to_tab(int ac, char **av);  // Declaration for ft_strs_to_tab
void ft_show_tab(t_stock_str *tab);              // Declaration for ft_show_tab

#endif
