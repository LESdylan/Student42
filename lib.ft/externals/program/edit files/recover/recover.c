/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:02:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 20:02:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512  // Each block is 512 bytes

// JPEG header pattern: 0xFF, 0xD8, 0xFF, 0xE0 to 0xEF
const uint8_t JPEG_HEADER[] = {0xFF, 0xD8, 0xFF};

int main(int argc, char *argv[])
{
    // Open the memory card image file
    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open file card.raw.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];  // Buffer to hold 512 bytes from the file
    int jpg_counter = 0;         // Counter for JPEG files
    FILE *outptr = NULL;         // Pointer for output JPEG file

    // Read blocks from the memory card until the end
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // Check for JPEG header (0xFF, 0xD8, 0xFF)
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF)
        {
            // If we've already found a JPEG, close the previous file
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            // Create a new JPEG file for the next JPEG found
            char filename[8];
            sprintf(filename, "%03i.jpg", jpg_counter);
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 2;
            }

            jpg_counter++;
        }

        // If a JPEG file is open, write the buffer to it
        if (outptr != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
        }
    }

    // Close the last JPEG file (if any)
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    // Close the input file
    fclose(inptr);

    return 0;
}

