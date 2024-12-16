/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:41:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 17:36:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The function ft_putnbr_fd is designed to print an integer n to a specified file descriptor fd. It handles both negative and positive integers by recursively breaking the number down and printing each digit.

Breakdown of the Code:
Handle Negative Numbers:

If n is negative (if (n < 0)), it first prints a minus sign (ft_putchar_fd('-', fd)), then converts n to its positive equivalent by multiplying by -1. The resulting number is then treated as a positive number for the subsequent logic.
Handle Positive Numbers:

If n is non-negative, it directly assigns it to num.
Recursion:

The function works recursively to print the digits of the number. It divides the number by 10 recursively (ft_putnbr_fd(num / 10, fd)) to break it down into its individual digits, and prints the digits starting from the least significant one (i.e., rightmost).
Base Case for Recursion:

The base case for the recursion is when num is less than 10. In this case, the function directly prints the digit using ft_putchar_fd.
Digit Conversion:

The expression (num % 10 + 48) converts the digit into its ASCII value. In ASCII, the character '0' has a value of 48, so adding 48 to the modulus operation result gives the correct character for the digit.
Suggested Improvements:
Optimization:
Although the current implementation is correct and clear, you can reduce the number of times ft_putchar_fd is called by using a more iterative approach, which avoids recursion and can be more efficient in terms of stack space (especially for large numbers).
Edge Case:
The function currently does not handle the INT_MIN case correctly because of the casting issue with unsigned int (-2147483648 is a special case since it can't be represented as a positive unsigned int). We can add a special check for INT_MIN to handle this correctly.
 */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + 48), fd);
}

/*
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	// Handle INT_MIN specifically as it cannot be cast directly to unsigned int
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;  // INT_MIN / 10
	}

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;

	// Use iterative approach to avoid deep recursion
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + 48), fd);
}
*/