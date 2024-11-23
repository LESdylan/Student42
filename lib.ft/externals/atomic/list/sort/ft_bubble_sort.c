/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:49:34 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/23 18:00:51 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * the bubble iterates through the array's values comparing adjacent values one at a times and swap them if they are in the incorrec
 * until the list is utterly ordered.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, temp;
    int vals[] = {5, 14, 154, 641500, 41111, 454, 25, 3, 0};
    int n = sizeof(vals) / sizeof(vals[0]);

    // Bubble Sort (ordre décroissant)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (vals[j] < vals[j + 1]) // Si l'élément courant est plus petit que le suivant
            {
                temp = vals[j];
                vals[j] = vals[j + 1];
                vals[j + 1] = temp;
            }
        }
    }

    // Afficher le tableau trié
    printf("Tableau trié en ordre décroissant : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", vals[i]);
    }
    printf("\n");

    return 0;
}
