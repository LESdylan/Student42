/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:35 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/11/11 13:38:28 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isalnum(int c)
{
    // Check if c is a digit (0-9), uppercase letter (A-Z), or lowercase letter (a-z)
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1; // Return 1 if true, indicating alphanumeric character
    return 0; // Return 0 if not alphanumeric
}

int main()
{
    // Test isalnum function with various inputs
    printf("isalnum('h') = %d\n", isalnum('h'));  // Lowercase letter
    printf("isalnum('H') = %d\n", isalnum('H'));  // Uppercase letter
    printf("isalnum('1') = %d\n", isalnum('1'));  // Numeric character
    printf("isalnum('!') = %d\n", isalnum('!'));  // Non-alphanumeric character

    return 0;
}
