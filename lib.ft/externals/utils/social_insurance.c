/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   social_insurance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:13:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/14 18:48:14 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

// Function prototypes
unsigned int check_sex(char *input);
unsigned int check_birth(char *input);
unsigned int check_month_birth(char *input);
unsigned int isnum(char *input);
unsigned int check_birth_number(char *input);
unsigned int check_key_control(char *input);
unsigned int is_valid(char *input);
unsigned int ft_strlen(char *input);
unsigned int ft_atoi(char *input);

int main(void)
{
    char *input = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if(input == NULL)
    {
        fprintf(stderr, "Error 1: Memory allocation failed\n");
        return 1;
    }

    while(1)
    {
        printf("Enter your social security number: ");
        if(fgets(input, BUFFER_SIZE, stdin) == NULL)
        {
            fprintf(stderr, "Error 2: Failed to read input\n");
            free(input);
            return 1;
        }

        // Remove newline if present
        size_t length = ft_strlen(input);
        if (length > 0 && input[length - 1] == '\n') 
            input[length - 1] = '\0';

        if (ft_strlen(input) < 15)
        {
            fprintf(stderr, "Error 3: Number must be at least 15 characters\n");
            continue;
        }
        
        if (is_valid(input) == 0)
        {
            fprintf(stderr, "Error 4: Invalid social security number\n");
            continue;
        }

        printf("\e[33mValid social security number\e[0m\n");
        break;
    }

    free(input);
    return 0;
}

// Convert string to integer
unsigned int ft_atoi(char *input)
{
    int result = 0;
    while (*input != '\0' && *input != '\n')
    {
        if (*input < '0' || *input > '9')
        {
            fprintf(stderr, "ERROR 5: Non-numeric character in input\n");
            return 0;
        }
        result = result * 10 + (*input - '0');
        input++;
    }
    return result;
}

// Measure the length of the input
unsigned int ft_strlen(char *input)
{
    int count = 0;
    while (*input != '\0')
    {
        count++;
        input++;
    }
    return count;
}

// Check if the first digit (sex identifier) is '1' or '2'
unsigned int check_sex(char *input)
{
    return (*input == '1' || *input == '2');
}

// Check the birth year (digits at positions 1 and 2)
unsigned int check_birth(char *input)
{
    return (input[1] >= '0' && input[1] <= '9' && input[2] >= '0' && input[2] <= '9');
}

// Check the month of birth (positions 3 and 4 should form a valid month)
unsigned int check_month_birth(char *input)
{
    if (input[3] == '0' && input[4] >= '1' && input[4] <= '9')
        return 1;
    if (input[3] == '1' && input[4] >= '0' && input[4] <= '2')
        return 1;
    return 0;
}

// Check if department code (positions 5 and 6) are valid digits
unsigned int isnum(char *input)
{
    return (input[5] >= '0' && input[5] <= '9' && input[6] >= '0' && input[6] <= '9');
}

// Check birth number (positions 10 to 13 should be digits)
unsigned int check_birth_number(char *str)
{
    for (int i = 10; i <= 13; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

// Check key control (positions 13 and 14 should be digits)
unsigned int check_key_control(char *input)
{
    for (int i = 13; i <= 14; i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return 0;
    }
    return 1;
}

// Validate the entire input format
unsigned int is_valid(char *input)
{
    return check_sex(input) &&
           check_birth(input) &&
           check_month_birth(input) &&
           isnum(input) &&
           check_birth_number(input) &&
           check_key_control(input);
}
