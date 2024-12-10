/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:06 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 12:45:28 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * the `strlcpy`function returns the total length of the string that would have beena copied if there was unlimited space.
 * This might or or might not be equal to the length of the create string actually, depending on wheter there was enough space.
 * This mean that you can call strlcpy() once to find out how much space is required, then allocate it if you do not have enough, and finally call strlcpy()
 * a second time to do the required copy.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t ft_strlcpy(char * restrict dest, const char * restrict src, size_t dstsize)
{
    size_t len = 0;

    if (dstsize > 0)
    {
        while (*src && --dstsize)
        {
            *(dest + len++) = *src++;
        }
        *(dest + len) = '\0';
    }
    while (*src++)
        len++;
    
    return len;
}

void print_buffer(const char *buffer, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (buffer[i] == '\0')
            printf("/");
        else
            printf("%c", buffer[i]);
    }
    printf("\n");
}

#define BUF_SIZE 20
#define N 50

int main(void)
{
    char srcBuffer[100] = {}; // initialize to 0, in order to avoid memories' shred.
    char destBuffer[BUF_SIZE] = {}; // Initialize to 0
    int j, i;
    char c;
    j = 0;
    srand(time(NULL));
    while (++j < 10)
    {
        i = 0;
        printf("##### ITERATION %d #####\n", j);
        puts("------------------------------------------------------------------------");

        // Génération de la chaîne aléatoire avec vérification de la taille
        while ((c = rand() % (126 - 32 + 1) + 32) != '~' && i < sizeof(srcBuffer) - 1)
            srcBuffer[i++] = c;
        srcBuffer[i] = '\0';

        // Affichage des informations sur srcBuffer
        printf("Max Size of srcBuffer :\t %lu\n", sizeof(srcBuffer));
        printf("Generated String :\t%s\t(length : %lu)\n", srcBuffer, strlen(srcBuffer));

        // Copie dans destBuffer avec ft_strlcpy
        printf("Size returned by ft_strlcpy :\t%lu\n", ft_strlcpy(destBuffer, srcBuffer, N));

        // Affichage du contenu de destBuffer avec une visualisation
        printf("destBuffer : ");
        print_buffer(destBuffer, sizeof(destBuffer));

        puts("------------------------------------------------------------------------\n");
    }

    return 0;
}