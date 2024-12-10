/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:54:14 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:54:16 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isprime_recursive(int n, int div) {
    if (div * div > n) {  // If div exceeds sqrt(n), it's prime
        return 1; // Prime
    }
    if (n % div == 0) { // If n is divisible by div, it's not prime
        return 0; // Not prime
    }
    return ft_isprime_recursive(n, div + 1); // Recurse with the next divisor
}

int ft_isprime(int n) {
    if (n <= 1) {
        return 0; // 0 and 1 are not prime
    }
    return ft_isprime_recursive(n, 2); // Start checking from 2
}
