/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:02:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:02:28 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

// Function to check if a base is valid
int is_base_valid(char *base) {
    int i, j;

    if (!base || !base[0] || !base[1]) // Base must have at least 2 characters
        return 0;
    for (i = 0; base[i] != '\0'; i++) {
        if (base[i] == '+' || base[i] == '-' || base[i] <= 32) // Base cannot have '+' or '-' or whitespaces
            return 0;
        for (j = i + 1; base[j] != '\0'; j++) {
            if (base[i] == base[j]) // Base cannot have duplicate characters
                return 0;
        }
    }
    return 1;
}

// Function to convert a number in base `base_from` to an integer
int ft_atoi_base(char *nbr, char *base_from) {
    int i = 0, sign = 1, result = 0, base_len = 0;
    while (base_from[base_len]) base_len++; // Find base length

    // Skip whitespaces and handle signs
    while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\r' || nbr[i] == '\v' || nbr[i] == '\f')
        i++;
    if (nbr[i] == '-' || nbr[i] == '+') {
        if (nbr[i] == '-') sign = -1;
        i++;
    }

    // Convert string to number based on base
    while (nbr[i]) {
        int value = -1;
        for (int j = 0; base_from[j] != '\0'; j++) {
            if (nbr[i] == base_from[j]) {
                value = j;
                break;
            }
        }
        if (value == -1) break; // Invalid character in number
        result = result * base_len + value;
        i++;
    }
    return sign * result;
}

// Function to convert an integer to a string in a specific base
char *ft_itoa_base(int nbr, char *base_to) {
    int base_len = 0, tmp = nbr, length = 1;
    while (base_to[base_len]) base_len++; // Find base length

    // Calculate the length of the result string
    if (nbr < 0) length++; // for negative numbers
    while (tmp /= base_len) length++;

    // Allocate memory for the result string
    char *result = (char *)malloc(sizeof(char) * (length + 1)); // +1 for the null terminator
    if (!result) return NULL;

    result[length] = '\0'; // Null-terminate the string
    if (nbr < 0) result[0] = '-'; // Add the sign for negative numbers

    // Convert the integer to the base
    if (nbr == 0) {
        result[0] = base_to[0]; // Handle zero case
    } else {
        int i = length - 1;
        if (nbr < 0) nbr = -nbr;
        while (nbr > 0) {
            result[i--] = base_to[nbr % base_len];
            nbr /= base_len;
        }
    }

    return result;
}

// Main function to convert a number from base_from to base_to
char *ft_convert_base(char *nbr, char *base_from, char *base_to) {
    if (!is_base_valid(base_from) || !is_base_valid(base_to)) return NULL;

    // Convert nbr to decimal
    int decimal_value = ft_atoi_base(nbr, base_from);

    // Convert the decimal value to the target base
    return ft_itoa_base(decimal_value, base_to);
}

int main() {
    char *nbr = "1011";
    char *base_from = "01"; // Binary base
    char *base_to = "0123456789abcdef"; // Hexadecimal base
    
    char *result = ft_convert_base(nbr, base_from, base_to);
    if (result != NULL) {
        printf("Converted number: %s\n", result);
        free(result);
    } else {
        printf("Conversion failed.\n");
    }

    return 0;
}
