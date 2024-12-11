/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:05:57 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:06:00 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

int main() {
    int a = -5;
    int b = 7;
    
    printf("The absolute value of %d is %d\n", a, ABS(a));  // Output: The absolute value of -5 is 5
    printf("The absolute value of %d is %d\n", b, ABS(b));  // Output: The absolute value of 7 is 7
    
    return 0;
}
