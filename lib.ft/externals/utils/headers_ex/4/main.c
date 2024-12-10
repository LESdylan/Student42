/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:11:04 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:14:46 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>       // For 'free'
#include "ft_stock_str.h"  // For function declarations and structure definition

int main(int argc, char **argv)
{
    // Call the function that converts strings to a tab of structures
    t_stock_str *tab = ft_strs_to_tab(argc - 1, &argv[1]);
    
    if (tab)
    {
        // Display the result using ft_show_tab
        ft_show_tab(tab);
        
        // Free memory for each string copy in the tab
        for (int i = 0; tab[i].str != 0; i++)
        {
            free(tab[i].copy);  // Free each string copy
        }
        
        // Finally, free the array of structures
        free(tab);
    }
    
    return 0;
}
