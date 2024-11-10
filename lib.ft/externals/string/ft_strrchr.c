/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan-soul <dylan-soul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:15 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/09/21 01:40:48 by dylan-soul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
char *ft_strrchr(const char *s, int c)
{
    int size = sizeof(s);
    int i;
    i = size - 1;
    while(*(s + i) !=  '\0' && i > 0)
    {
        if(*(s + i) == c)
            return (char *)s;
        i--;
    }
    return 0;
}
int main(void)
{
    const char *s = "hello world";
    int c = 111;
    printf("the result is : %s", ft_strrchr(s, c));
}