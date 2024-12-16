/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:24:27 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:25:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_strdup(s);
	if (!s || !f || !str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}

/**
 * !IMPROVED VERSION
 * Key Improvements:
*   *Input Validation:
*   *
*   *Moved if (!s || !f) before memory allocation to ensure that the function pointer f and the string s are valid before proceeding.
*   *Memory Allocation:
*   *
*   *Added a comment explaining the purpose of ft_strdup for better readability.
*   *Use Original Input (s) for Iteration:
*   *
*   *While the original implementation modifies the duplicated string directly, it's cleaner to iterate over s and then modify str. This avoids modifying the duplicate string in place, which is less intuitive.
*   *Readability:
*   *
*   *Organized the flow of the function to improve clarity, especially separating validation, memory allocation, and logic into distinct steps.
*   *Safety:
*   *
*   *Removed redundant checks (!s || !f || !str) after allocation since s and f are already validated.
 *
 * 
 *  char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	// Validate input
	if (!s || !f)
		return (NULL);

	// Allocate memory for the new string
	str = ft_strdup(s);
	if (!str)
		return (NULL);

	// Apply the function to each character of the string
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}

	return (str);
}
 * 
 */