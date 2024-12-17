/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:25:21 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 20:29:25 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int swap(sa, sb, ss) // Swap the first two elements of a stack
int push(pa, pb) // Push the top element from one stack to another
int rotate(ra,rb,rr) //Rotate a stack so that the first element moves to the end
int reverse_rotate(rra,rrb,rrr)// rotate a stack in the opposite direction
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = parse_args(argc, argv); // Function to convert input into stack
    b = NULL;
    if (is_sorted(a))
        return (0); // If already sorted, no need to do anything

    // Your sorting algorithm
    sort_stack(a, b);
    return (0);
}


