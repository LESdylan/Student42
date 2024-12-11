/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:18:18 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:18:58 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // for NULL

void ft_striter(char *s, void (*f)(char *))
{
    // Check if the string and function are not NULL
    if (s && f)
    {
        // Iterate through each character of the string
        while (*s)
        {
            // Apply the function f to the current character
            f(s);
            // Move to the next character
            s++;
        }
    }
}

#include <stdio.h>
#include <ctype.h>  // for toupper

// Function that converts a character to uppercase
void to_uppercase(char *c)
{
    if (*c >= 'a' && *c <= 'z')
    {
        *c = (char)toupper((unsigned char)*c);  // Convert to uppercase
    }
}

int main()
{
    // Allocate memory for a string
    char str[] = "hello, world";

    // Print the string before modification
    printf("Before ft_striter: %s\n", str);

    // Apply to_uppercase to each character of the string using ft_striter
    ft_striter(str, to_uppercase);

    // Print the modified string
    printf("After ft_striter: %s\n", str);  // Should print "HELLO, WORLD"

    return 0;
}
