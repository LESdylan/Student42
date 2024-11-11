/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan-soul <dylan-soul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:02 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/09/21 01:00:39 by dylan-soul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//postponed.
#include <string.h>
#include <stdio.h>
int main()
{
    const char *str = "hello world";
    const char *str2 = "hello world2";
    printf("%s", strdup(str));
    return 0;
}