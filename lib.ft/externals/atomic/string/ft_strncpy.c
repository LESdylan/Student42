/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:43:08 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:43:10 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*	THEORY
	~Good article -> https://lwn.net/Articles/507319/
	~I have to copy N char from source to dest
	~If (N > source) i will pad [N - source] of 0s into dest.  
  	~Returns a pointer to dest

	1)
	strncpy() is not intended to be used as a safer strcpy(), 
	💡it is supposed to be used to insert one string in the middle of another💡
	That's why not '\0' is added.
	If there is no null byte among the first N bytes of src, the string placed in dest will not be null terminated.
	2)
	strncpy was never intended to be a "safe alternative" to strcpy,
   	though that is the impression a lot of new C programmers get since it does take a "size" parameter.
   	💡The third argument is for the number of char to be read from the source buffer, not the maximum capacity of the destination buffer💡
*/
/*char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
    char *original_dest = dest; // Save the start of the destination

    while (n > 0 && *src != '\0') // Copy up to n characters or until the source string ends
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    
    while (n > 0) //Null-terminate the rest of the destination string if n is still positive
    {
        *dest = '\0';
        dest++;
        n--;
    }
    
    return original_dest;  //Return the beginning of the destination string
}*/
// or *ft_strncpy other version

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	int i;
	i = 0;
	while(*src != '\0' && n)
		*(dest + i++) = *src++;
		--n;
	while(n--)
		*(dest + i++) = '\0';
	return(dest);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 60
// Function to print buffer content, showing '/' for empty spaces
void print_buffer(const char *buffer, size_t size) {
	int count;
	count = 0;
    for (size_t i = 0; i < size; i++) {
        if (buffer[i] != '\0') {
            putchar(buffer[i]);
			count++;
        } else {
            putchar('*'); // Represent empty space with '/'
        }
    }
	printf("\tpadding [%lu-%u] = %lu", size, count, (size - count));
    puts("\n\n");
}

// Function to print an empty buffer (all '/')
void print_empty_buffer(size_t size) {
    for (size_t i = 0; i < size; i++) {
        putchar('*'); // Represent all spaces with '/'
    }
    puts("\n\n");
}

int main(void) 
{
    char srcBuffer[50];
    char destBuffer[BUF_SIZE];
    int i, j, n;
    char c;

    j = 0;
    n = 70;
    srand(time(NULL));
    while (++j < 10) {
        i = 0;
        // Generating random string
        while ((c = rand() % (126 - 32 + 1) + 32) != '~' && i < sizeof(srcBuffer) - 1) {
            srcBuffer[i++] = c;
        }
        srcBuffer[i] = '\0';
        printf("##### NEW ITERATION %d\n", j);
		puts("---------------------------------------------------------------------------------------");
		puts("INFORMATION: ");
		printf("source_buffer \t size is ------> %lu, \t length is -----> %lu\n", sizeof(srcBuffer), strlen(srcBuffer));
		printf("destBuffer \t size is ------> %lu\n", sizeof(destBuffer));
        printf("The generated string is:\t%s\t(Size: %lu)\n", srcBuffer, strlen(srcBuffer));

        // Print completely empty buffer for contrast
        printf("Completely empty buffer: ");
        print_empty_buffer(BUF_SIZE);

        // Using strncpy
        memset(destBuffer, 0, sizeof(destBuffer)); // Clear destBuffer
        strncpy(destBuffer, srcBuffer, n);
        destBuffer[BUF_SIZE - 1] = '\0'; // Ensure null-termination
        
        printf("Dest Buffer after strncpy(): ");
        print_buffer(destBuffer, BUF_SIZE);

        // Using custom ft_strncpy
        memset(destBuffer, 0, sizeof(destBuffer)); // Clear destBuffer again
        ft_strncpy(destBuffer, srcBuffer, n);
        
        printf("Dest Buffer after ft_strncpy(): ");
        print_buffer(destBuffer, BUF_SIZE);
        puts("---------------------------------------------------------------------------------------\n\n\n");
    }
    return 0;
}




/*
#define N 60
#define BUF_SIZE 60

int main()
{
	char	srcBuffer[256];
	char	dstBuffer[BUF_SIZE];
	int 	j;
	char	c;

	for (int i=0; i<10; ++i)
	{
		//Refresh j
		j = 0;
		//Clean the buffers
		for (int i=0; i<BUF_SIZE; ++i)dstBuffer[i]='/';
		for (int i=0; i<256; ++i)srcBuffer[i]=0;

		//Fill source with random chars
		while ((c = rand()%27 + 97) != 123)srcBuffer[j++] = c;
		//Sentinel '\0'
		srcBuffer[j] = '\0';

		printf("-----------------------------------------"
				"\nIf (N > source) i will pad [%d - %lu] of 0s dest."  
				"\n\n\nSource Buffer                -> %s Len->%lu\n", N, strlen(srcBuffer), *srcBuffer ? srcBuffer : "Empty line", strlen(srcBuffer));
		printf("Dest Buffer before function  -> %s Len-> %lu\n", dstBuffer, strlen(dstBuffer));
		printf("Elements to copy           N -> %d\n", N);
		printf("Dest Buffer after real function   -> %s\n", strncpy(dstBuffer, srcBuffer, N));

		//Check the bytes
		printf("BYTES IN MY DEST BUFFER AFTER STRNCPY ORIGINAL\n");
		for (int i=0; i<BUF_SIZE; ++i) 
			(dstBuffer[i] == 0) ? printf("0") : printf("%c ", dstBuffer[i]);
		printf("\n\n------------------------------------------\n");
		
		for (int i=0; i<BUF_SIZE; ++i)dstBuffer[i]='/';
		printf("Dest Buffer after my function     -> %s\n", ft_strncpy(dstBuffer, srcBuffer, N));
 		printf("BYTES IN MY DEST BUFFER AFTER MY FT_STRNCPY \n");
		for (int i=0; i<BUF_SIZE; ++i)
			(dstBuffer[i] == 0) ? printf("0") : printf("%c ", dstBuffer[i]);
		printf("\n\n------------------------------------------\n\n\n\n\n\n\n\n");
	}

}
*/