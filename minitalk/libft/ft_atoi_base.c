/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:33 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 17:33:09 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_atoi_base(unsigned long long n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

/*
#include "libft.h"

static size_t	ft_len(unsigned long long n, size_t base_len)
{
	size_t	len;

	len = 1;
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static int		is_valid_base(char *base)
{
	size_t	i;
	size_t	j;

	if (!base || ft_strlen(base) < 2)
		return (0); // Base is too short to be valid

	// Check if the base contains any duplicate characters
	for (i = 0; base[i]; i++)
	{
		for (j = i + 1; base[j]; j++)
		{
			if (base[i] == base[j])
				return (0); // Duplicate characters found
		}
	}

	return (1);
}
*/
/** 
 * !Key Improvements:
 * *Base Validation:
 * *
 * *A new helper function is_valid_base checks if the base is valid. It ensures that:
 * *The base has at least two characters.
 * *The base doesn't contain duplicate characters.
 * *Early Return for Zero:
 * *
 * *If n is 0, we immediately return the string "0", which is more efficient than going through the entire conversion process.
 * *Optimized Memory Allocation:
 * *
 * *We now only calculate the base length once and use it consistently in both the ft_len function and the main logic.
 * *Improved Error Handling:
 * *
 * *The function returns NULL if the base is invalid, ensuring the user knows if they've provided an incorrect base.
 * *Slightly Cleaner Logic:
 * *
 * *The logic is streamlined for clarity. For example, instead of reducing num_len each time inside the loop, we decrement it before assigning the base character.
 * 
 * 
 * char	*ft_atoi_base(unsigned long long n, char *base)
 * {
 * 	char	*str;
 * 	size_t	num_len;
 * 	size_t	base_len;
 * 
 * 	if (!is_valid_base(base))
 * 		return (NULL); // Invalid base
 * 
 * 	base_len = ft_strlen(base);
 * 	if (n == 0)
 * 	{
 * 		str = ft_calloc(2, sizeof(char)); // Only need space for "0" and '\0'
 * 		if (!str)
 * 			return (NULL);
 * 		str[0] = '0';
 * 		return (str);
 * 	}
 * 
 * 	num_len = ft_len(n, base_len);
 * 	str = ft_calloc((num_len + 1), sizeof(char)); // +1 for null terminator
 * 	if (!str)
 * 		return (NULL);
 * 
 * 	// Fill the string with the base characters
 * 	while (num_len > 0)
 * 	{
 * 		str[--num_len] = base[n % base_len];
 * 		n /= base_len;
 * 	}
 * 
 * 	return (str);
 * }
 * 
 * 
 */