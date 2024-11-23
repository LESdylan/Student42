/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:06:15 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/23 18:35:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int main()
{
    int i, j, temp, maxindex;
    int vals[] = {5, 14, 154, 641500, 41111, 454, 25, 3, 0};
    int n = sizeof(vals) / sizeof(vals[0]);
    
    i = -1;
    while (++i < n - 1)
    {
        j = i;
        maxindex = i;
        while (++j < n)
        {
            if (vals[maxindex] < vals[j])
            {
                maxindex = j;
            }
        }
        if (maxindex != i)
        {
            temp = vals[i];
            vals[i] = vals[maxindex];
            vals[maxindex] = temp;     
        }
    }
    printf("Tableau trié en ordre décroissant : ");
    for (i = 0; i < n; i++)
        printf("%d ", vals[i]);
    printf("\n");
    return 0; // Indiquer succès
}
