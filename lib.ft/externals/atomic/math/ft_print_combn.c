/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:23:46 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/27 00:03:31 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Fonction récursive pour générer les combinaisons
void generate_comb(int n, int start, char *combination, int index)
{
    // Si la combinaison est complète, l'afficher
    if (index == n)
    {
        for (int i = 0; i < n; i++)
            ft_putchar(combination[i]);
        if (combination[0] != '9' - (n - 1)) // Évite une virgule après la dernière combinaison
        {
            ft_putchar(',');
            ft_putchar(' ');
        }
        return;
    }

    // Parcourir les chiffres possibles
    for (int digit = start; digit <= 9; digit++)
    {
        combination[index] = digit + '0'; // Ajouter le chiffre actuel
        generate_comb(n, digit + 1, combination, index + 1); // Appel récursif
    }
}

// Fonction principale pour afficher les combinaisons
void ft_print_combn(int n)
{
    char combination[10]; // Stocker jusqu'à 10 chiffres (n <= 9 selon la consigne)
    generate_comb(n, 0, combination, 0); // Lancer la génération
}

// Exemple d'utilisation
int main(void)
{
    ft_print_combn(9); // Test avec n = 2
    return 0;
}
