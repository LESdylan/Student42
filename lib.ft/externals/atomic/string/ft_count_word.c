/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:07:01 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/11 23:12:44 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h> // pour isalpha

int ft_count_word(char *str)
{
    int in_word = 0;
    int count = 0;

    while (*str != '\0')
    {
        if (isalpha(*str))
        {
            if (in_word == 0)
            {
                count++;
                in_word = 1;
            }
        }
        else if (*str == '\'' || *str == '-' || *str == '_')
        {
            // Vérifier si la ponctuation est suivie d'une lettre pour la traiter comme un mot
            if (isalpha(*(str + 1)))
            {
                str++;
                continue;
            }
            else
            {
                in_word = 0; // Ne pas compter comme mot si non suivi d'une lettre
            }
        }
        else
        {
            in_word = 0; // Autre ponctuation ou espace
        }
        str++;
    }
    return count;
}

int main()
{
    char *text = "Congratulations! Today is your day. You're -  ' off-track to Great Places! You're off and away!";
    printf("number fo words : %d\n", ft_count_word(text));
    return  0;
}