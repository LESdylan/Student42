/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:19:19 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:19:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // for NULL

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    // Check if the string and function are not NULL
    if (s && f)
    {
        unsigned int i = 0;

        // Iterate through each character of the string
        while (*s)
        {
            // Apply the function f to the current character and its index
            f(i, s);
            // Move to the next character
            s++;
            // Increment the index
            i++;
        }
    }
}
#include <stdio.h>
#include <ctype.h>  // for toupper and tolower

// Function that modifies a character based on its index
void modify_char(unsigned int index, char *c)
{
    // If the index is even, convert to uppercase; if odd, convert to lowercase
    if (index % 2 == 0)
    {
        *c = (char)toupper((unsigned char)*c);  // Convert to uppercase
    }
    else
    {
        *c = (char)tolower((unsigned char)*c);  // Convert to lowercase
    }
}

int main()
{
    // Allocate memory for a string
    char str[] = "hello, world";

    // Print the string before modification
    printf("Before ft_striteri: %s\n", str);

    // Apply modify_char to each character of the string using ft_striteri
    ft_striteri(str, modify_char);

    // Print the modified string
    printf("After ft_striteri: %s\n", str);  // Should print "HeLlO, WoRlD"

    return 0;
}
