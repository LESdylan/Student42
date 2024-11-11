/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:38 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/11/11 12:54:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_isalpha(int c) {
    // Check if character is a letter (uppercase or lowercase)
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return (1);
    }
    return (0);
}

int main() {
    // Testing ft_isalpha function with 'h'
    printf("ft_isalpha('h') = %d\n", ft_isalpha('h'));
    // You can test with other characters too
    printf("ft_isalpha('H') = %d\n", ft_isalpha('H'));
    printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
    return 0;
}
