/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:19:44 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:20:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input and output files
    FILE *input = fopen(argv[1], "rb");  // Use "rb" for binary read mode
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb"); // Use "wb" for binary write mode
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input);
        return 1;
    }

    // Read the scaling factor for volume adjustment
    float factor = atof(argv[3]);
    if (factor <= 0)
    {
        printf("Invalid scaling factor. Factor must be greater than 0.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Buffer to hold the .wav header
    uint8_t header[HEADER_SIZE];
    
    // Read header from input file
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);

    // Write header to output file (this does not change)
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Determine the size of the audio data
    // This can be derived from the "Subchunk2Size" field in the header (bytes 40-43)
    uint32_t data_size = *(uint32_t *)&header[40];
    uint32_t sample_count = data_size / 2;  // Assuming 16-bit samples (2 bytes each)

    // Buffer to hold audio data (16-bit samples)
    int16_t *samples = (int16_t *)malloc(data_size);

    if (samples == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Read the audio samples from the input file
    fread(samples, sizeof(int16_t), sample_count, input);

    // Adjust the volume by scaling the samples
    for (uint32_t i = 0; i < sample_count; i++)
    {
        int32_t new_sample = (int32_t)(samples[i] * factor);
        // Ensure the sample stays within the 16-bit signed integer range
        if (new_sample > INT16_MAX)
        {
            samples[i] = INT16_MAX;
        }
        else if (new_sample < INT16_MIN)
        {
            samples[i] = INT16_MIN;
        }
        else
        {
            samples[i] = (int16_t)new_sample;
        }
    }

    // Write the adjusted samples to the output file
    fwrite(samples, sizeof(int16_t), sample_count, output);

    // Clean up and close files
    free(samples);
    fclose(input);
    fclose(output);

    printf("Volume adjustment complete.\n");
    return 0;
}
