/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:07 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:37:35 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // for write
#include <string.h>  // for strlen

void ft_putendl(char const *s)
{
    // Check if the string is not NULL
    if (s)
    {
        // Output the string using write(2)
        write(1, s, strlen(s));

        // Output a newline character
        write(1, "\n", 1);
    }
}
#include <stdio.h>

int main()
{
    char str[] = "Hello, World!";
    
    // Test ft_putendl
    ft_putendl(str);  // Should print "Hello, World!" followed by a newline
    
    return 0;
}
