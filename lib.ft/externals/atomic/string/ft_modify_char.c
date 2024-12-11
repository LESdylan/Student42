/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:21:55 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:22:00 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char modify_char(unsigned int index, char c)
{
    if (index % 2 == 0)
    {
        return (char)toupper((unsigned char)c);  // Convert to uppercase if index is even
    }
    else
    {
        return (char)tolower((unsigned char)c);  // Convert to lowercase if index is odd
    }
}