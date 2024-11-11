/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:07:01 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/11 14:57:32 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_count_word(char *str)
{
    int new_word = 0;
    int count = 0;
    while(*str != '\0')
    {
        if(isalpha(*str))
        {
            if (new_word == 0)
            {
                count++;
                new_word = 1;
            }
        } else 
        {
            new_word = 0;
        }
        str++;
    }
    return count;
}

int main()
{
    char *text = "Hello, world! This is a test .";
    printf("number fo words : %d\n", ft_count_word(text));
    return  0;
}