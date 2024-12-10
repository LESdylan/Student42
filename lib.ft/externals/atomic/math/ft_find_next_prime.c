/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:54:36 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:54:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_find_next_prime_recursive(int n) {
    if (ft_isprime(n)) { // If n is prime, return it
        return n;
    }
    return ft_find_next_prime_recursive(n + 1); // Otherwise, check the next number
}

int ft_find_next_prime(int n) {
    if (n <= 1) {
        return 2; // The next prime after 1 is 2
    }
    return ft_find_next_prime_recursive(n);
}
