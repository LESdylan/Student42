/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:18:08 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:18:16 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stock_str
{
    int size;
    char *str;
    char *copy;
} t_stock_str;

void ft_show_tab(struct s_stock_str *par);
