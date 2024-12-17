/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:05:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 21:11:09 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    if(1 == argc || (2 == argc && !argv[1][0]))
        return (1);
    else if(2 == argc)
        argv = ft_split(argv[1], ' ');
    stack_init(&a, argv + 1, 2 == argc);
    if (!stack_sorted(a))
    {
        if (!stack_sorted(a))
            sa(&a, false);
        else if (stack_len(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
}