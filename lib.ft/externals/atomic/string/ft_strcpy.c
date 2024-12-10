/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:43:27 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:43:29 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
char    *ft_strcpy(char *dest, char *src)
{
    int i;
    
    i = 0;
    while(*src)
        *(dest + i++) = *src++;
    *(dest + i) = '\0';
    return (dest); 
}
*/
#define BUF_SIZE 256

// Function prototype for ft_strcpy (your custom strcpy)
char *ft_strcpy(char *dest, const char *src);

int main(void)
{
    char srcBuffer[100];
    char destBuffer[BUF_SIZE];
    char c;
    int j;
    int i;
    char *str;

    // Seed the random number generator
    srand(time(NULL));

    j = 0;

    while (++j < 10) 
    {
        i = 0;
        // Generate random printable characters from ASCII 32 (' ') to 126 ('~')
        while ((c = rand() % (126 - 32 + 1) + 32) != '~' && i < sizeof(srcBuffer) - 1) // '~' will terminate the string
            srcBuffer[i++] = c;
        srcBuffer[i] = '\0';

        // Display the generated random string and its size
        puts("The random string:");
        printf("------------------------------------------------------------------------------\n");
        printf("srcBuffer size: %lu bytes\n", sizeof(srcBuffer));
        printf("The generated string is:\t%s\t(Size: %lu)\n", srcBuffer, strlen(srcBuffer));

        // Check for potential buffer overflow
        if (strlen(srcBuffer) >= BUF_SIZE) {
            printf("Warning: srcBuffer size exceeds destBuffer capacity (BUF_SIZE = %d)\n", BUF_SIZE);
        }

        // Use strcpy to copy srcBuffer to destBuffer
        str = strcpy(destBuffer, srcBuffer);
        puts("\nUsing strcpy:");
        printf("Copied string (strcpy):\t\t%s\t(Size: %lu)\n", str, strlen(str));

        // Clear destination buffer for next iteration
        memset(destBuffer, 0, sizeof(destBuffer));

        // custom ft_strcpy to copy srcBuffer to destBuffer
        str = ft_strcpy(destBuffer, srcBuffer);
        puts("\nUsing ft_strcpy:");
        printf("Copied string (ft_strcpy):\t%s\t(Size: %lu)\t()\n", str, strlen(str));

        puts("------------------------------------------------------------------------------\n\n\n");
    }

    return 0;
}

// Your custom strcpy function (ft_strcpy)
char *ft_strcpy(char *dest, const char *src)
{
    char *dest_start = dest;

    // Copy characters from src to dest
    while ((*dest++ = *src++));
    *(dest++) = '\0';
    // Return pointer to the start of the destination buffer
    return dest_start;
}




/*
#define BUF_SIZE 100

int main(void)
{
    char    srcBuffer[256];
    char    destBuffer[BUF_SIZE];
    char    c;
    int     i;
    
    i = 0;
    
    for(int j=0; j<10; j++)
    {
        i = 0;
        //Create a random string in srcBuffer
        while((c = rand()%27+'a') != 123)
            srcBuffer[i++] = c;
        //My final sentinel
        srcBuffer[i] = 0;
        //Refresh i for next iteration
        i = 0;
        
        //Check if algo correct
        puts("RANDOM STRING SOURCE");
        //Ternary operator
        (*srcBuffer) ? printf("%s SIZE -> %lu\n", srcBuffer, strlen(srcBuffer)) : puts("empty string");
        
        // I can feed directly the function to printf, cause return value is dest
        printf("DEST BUFFER SIZE -> %d\n", BUF_SIZE);
        printf("\nFrom the original function ->                        DEST = %s\n", strcpy(destBuffer, srcBuffer));
        
        //clean the buffer
        for(int i = 0; i<BUF_SIZE; ++i)destBuffer[i] = 0;
        printf("From my function->                                     DEST = %s\n\n\n", ft_strcpy(destBuffer, srcBuffer));
        printf("-------------------------------------------\n\n");
    }
}
*/