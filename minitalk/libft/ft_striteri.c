/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:31:09 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:32:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/**
 * 
 *  !Key Improvements
*   *Input Validation:
*   *
*   *Added a check to ensure both s (the string) and f (the function pointer) are not NULL. This prevents potential segmentation faults if the function is called with invalid arguments.
*   *Improved Readability:
*   *
*   *Added spacing and clarified the flow to make the code easier to read and maintain.
*   *No Functional Changes:
*   *
*   *The core logic remains the same: iterating through the string and applying the function f to each character by passing its address and index.
 * 
 * 
 * 
 * #include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

 */