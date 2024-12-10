/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:53:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:53:03 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// version iterative
/*
int ft_sqrt(int nb)
{
    int i;
    i = 1;
    while(i < nb)
    {
        if(nb % i == 0 &&  (i * i) == nb)
            return i;
        i++;
    }
    return (0);
}
// version recursive
*/

// Recursive function for Newton's method
int newton_sqrt(int N, int x) {
    int next_x = 0.5 * (x + N / x);  // Next approximation

    // If the difference is within the tolerance, stop recursion
    if ((next_x - x) < 1e-0 && (x - next_x) < 1e-0
) {
        return next_x;
    }
    return newton_sqrt(N, next_x);
}

// Function to initiate the Newton's method recursion
int sqrt_newton(int N) {
    // Handle edge case for non-positive numbers
    if (N < 0) {
        printf("Cannot compute square root of a negative number.\n");
        return -1;
    } else if (N == 0) {
        return 0;
    }

    // Start recursion with an initial guess, N / 2 is a reasonable starting point
    return newton_sqrt(N, N / 2);
}

int main() {
    int N;

    // Input the number to find the square root of
    printf("Enter a number: ");
    scanf("%d", &N);

    // Call the Newton's method square root function
    int result = sqrt_newton(N);
    
    // If valid, print the result
    if (result != -1) {
        printf("The square root of %d is approximately %d\n", N, result);
    }
    return 0;
}
/*
int main(void)
{
    int nb = 25;
    printf("%d\n",ft_sqrt(nb));
    return 0;   
}
*/