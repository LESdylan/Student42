/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primarily_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:25:13 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 02:53:20 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * !https://brilliant.org/wiki/prime-numbers/
 */
#include <stdio.h>
int is_prime_number(int n);
int main(void)
{
       printf("%d\n", is_prime_number(2017));
       return 0;
}

int is_prime_number(int n)
{
    if(n <= 1)
        return 0;
    int permu = 1;
    int i = 1;
    while(++i < n)
        permu = (permu * i) %n;
    
    if(permu== n-1)
        return 1;
    printf("%d\n", permu);
    return 0;
}

int bertrand(int n)
{
    return;
}
int mersenne(int n)
{
    return;
}
int euclid(int n)
{
    return;
}

int euler(int n)
{
    return;
}
int fermat(int n)
{
    return;
}
int emirps(int n)
{
    return;
}
int sieve_erathostene(int n)
{
    return;
}

/**
 * write an algortihm that generate all the prime number
 * ! rules ! : prime numbers are numbers whose only factors are one and itself as opposite of composite number that can have other factors
 * ? find the rule behind the prime numbers.
 * ? every integer greater than 1 is either prime or composite
 * ?eliminiation algorithm
 */

#include <stdio.h>
int main(void)
{
    int i;
    i = 0;
    while(i < 100)
    {
        if(i == 2 || i == 7 || i == 5)
        {
            printf("%i\n", i);
        }
        if(i > 9 &&  i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0)
        {
            printf("\e[31m%i\e[0m\n", i);
        }
        i++;
    }
    return 0;
}

