/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:06:46 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:06:52 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

// Define the t_point structure with two integer members, x and y
typedef struct s_point {
    int x;
    int y;
} t_point;

// Function declaration for set_point, which modifies the x and y of a t_point
void set_point(t_point *point);

#endif
