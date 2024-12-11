/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:05:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:05:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i = -1;
    int j;
    while(++i < height)
    {
        j = -1;
        while(++j < width)
        {
            //calculate the average value intensity
            BYTE average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;

            //Set all color channels to the average
            image[i][j].rgbtRed=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;

        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i,j;
    i = -1;
    while(++i < height)
    {
        j = -1;
        while(++j < width)
        {
            //Store original Colors for one pixel;
            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalBlue = image[i][j].rgbtBlue;
            BYTE originalGreen = image[i][j].rgbtGreen;
            // Store original Colors
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
        }
    }
    //for (int i = 0; i < height; i++)
    //{
    //    for (int j = 0; j < width; j++)
    //    {
    //        // Store original colors
    //        BYTE originalRed = image[i][j].rgbtRed;
    //        BYTE originalGreen = image[i][j].rgbtGreen;
    //        BYTE originalBlue = image[i][j].rgbtBlue;
//
    //        // Calculate new sepia values
    //        int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
    //        int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
    //        int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
//
    //        // Ensure values are within bounds
    //        image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
    //        image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
    //        image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
    //    }
    //}
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j;
    while(++i < height)
    {
        j = -1;
        while(++j < width / 2)
        {
            //swap pixels on opposite sides
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width -j -1] = temp;
        }
    }
    return;
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i,j,di,dj,redSum, greenSum, blueSum, count;
    //Create a temporary copy of the image
    RGBTRIPLE temp[height][width];

    i = -1;
    while(++i < height)
    {
        j = -1;
        while(++j < width)
        {
            temp[i][j] = image[i][j];
        }
    }
    //apply the blur
    int blur_level = -2;
    i = -1;
    while (++i < height)
    {
        j = -1;
        while(++j < width)
        {
            redSum = 0;
            greenSum = 0;
            blueSum = 0;
            count =0;

            di = blur_level;
            while(++di <= 1)
            {
                dj =blur_level;
                while(++dj <= 1)
                {
                    int ni = i +di;
                    int nj = j +dj;

                    if(ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redSum += temp[ni][nj].rgbtRed;
                        greenSum += temp[ni][nj].rgbtGreen;
                        blueSum += temp[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = redSum +50/ count ;
            image[i][j].rgbtBlue = blueSum / count;
            image[i][j].rgbtGreen = greenSum+50 / count;

        }
    }
    return;
}
