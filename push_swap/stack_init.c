/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:53:23 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/17 01:13:20 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * atol, i need it to check eventual overflows
 * converting every string into a long value
 */

static long ft_atol(const char *str)
{
    long    num;
    int     isneg;
    int     i;

    num = 0;
    isneg = 1;
    i = 0;
    while (str[i] && str[i] == ' ' || str[i] == '\t'
            || str[i] == '\n' || str[i] == '\r'
            || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) +  (str[i] - '0');
        i++;
    }
    return(num * isneg);
}

/**
 * Create the stack with the command line values
 * Checks are embedded in the createion itself
 *      ¬ duplicatevalues
 *      ¬ over |underflow
 *      ¬Syntax errors
 * flag is useufl cause if true, I have the argv in the HEAP to free
 */
void    stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
    long    nbr;
    int     i;

    i = 0;
    while(argv[i])
    {
        if (error_syntax(argv[i]))
            error_free(a, argv, flag_argc_2);
        nbr = ft_atol(argv[i]);
        if (nbr > INT_MAX  || nbr < INT_MIN)
            error_free(a, argv, flag_argc_2);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv, flag_argc_2);
        append_node(a, (int)nbr);
        ++i;

    if (flag_argc_2)
        free_matrix(argv);
    ++argv;
    // TEST
    printf("%p Pointer from main change only once "
            "when changing from NULL to l node \n", *a);
    }
}

int main()
{
    t_stack_node *a;
    a = NULL;
    printf("%p Pointer from main initially\n", a);
    char *v[5] = {v[0] = "\0", v[1] = "42", v[2]="1337", v[3] = "-21", v[4] = NULL};
    stack_init(&a, v+1, false);
    while (a)
    {
        printf("\n%d, \t node with address %p\n" , a->value, a);
        a = a->next;
    }
}
