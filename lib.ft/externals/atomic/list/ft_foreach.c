/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:41:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 14:41:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// ft_foreach function definition
void ft_foreach(int *tab, int length, void(*f)(int)) {
    for (int i = 0; i < length; i++) {
        f(tab[i]);  // Apply the function f to each element of the array
    }
}

// Example function to be passed as a pointer to ft_foreach
void ft_putnbr(int n) {
    printf("%d\n", n);
}

int main() {
    int tab[] = {1, 2, 3, 4, 5};  // Example array
    int length = 5;  // Length of the array
    
    // Call ft_foreach to print all elements in the array
    ft_foreach(tab, length, &ft_putnbr);
    
    return 0;
}
