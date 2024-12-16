/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:32:16 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:33:23 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{	
	char	*s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}


/**
 * 
 * 
 *  !Key Improvements
*   * Null Input Validation:
*   * 
*   * Added a check to ensure s1 is not NULL before proceeding. While the standard strdup doesn't check for NULL, this ensures safety for any potential misuse.
*   * Efficient ft_memcpy Call:
*   * 
*   * The ft_memcpy call now uses size directly (calculated earlier) instead of recomputing ft_strlen(s1) + 1 during the function call.
*   * Clearer Comments:
*   * 
*   * Added comments to improve readability, especially to clarify why +1 is added (for the null terminator).
*   * No Redundant Calls:
*   * 
*   * Avoided calculating ft_strlen(s1) multiple times by storing the result in size.

 * #include "libft.h"

char	*ft_strdup(const char *s1)
{	
	char	*s2;
	size_t	size;

	if (!s1)
		return (NULL);

	size = ft_strlen(s1) + 1; // Include space for the null terminator
	s2 = (char *)malloc(size);
	if (!s2)
		return (NULL);

	ft_memcpy(s2, s1, size); // Copy the entire string including '\0'
	return (s2);
}

 */