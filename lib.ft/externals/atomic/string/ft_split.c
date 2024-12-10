/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:44:36 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:28:56 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int count_words(const char *str, char delimiter) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (*str == delimiter) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

static char *strdup_delimited(const char *start, const char *end) {
    size_t len = end - start;
    char *substr = (char *)malloc(len + 1);
    if (!substr) return NULL;
    strncpy(substr, start, len);
    substr[len] = '\0';
    return substr;
}

char **ft_split(const char *str, char delimiter) {
    int word_count = count_words(str, delimiter);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result) return NULL;

    int i = 0;
    const char *start = str;
    while (*str) {
        if (*str == delimiter || *(str + 1) == '\0') {
            if (*str != delimiter) str++;  // Include last word
            result[i++] = strdup_delimited(start, str);
            start = str + 1;
        }
        str++;
    }

    result[i] = NULL;  // Null-terminate the array
    return result;
}

// Test function
#include <stdio.h>
int main() {
    const char *input = "Hello World from C";
    char **split_result = ft_split(input, ' ');

    for (int i = 0; split_result[i]; i++) {
        printf("%s\n", split_result[i]);
        free(split_result[i]);
    }
    free(split_result);

    return 0;
}


/*
#include <stdlib.h>

// Function to check if a character is in the charset
int is_charset(char c, char *charset)
{
    while (*charset)
    {
        if (c == *charset)
            return 1;
        charset++;
    }
    return 0;
}

// Function to count the number of substrings in str separated by charset
int count_substrings(char *str, char *charset)
{
    int count = 0;
    int in_substring = 0;

    while (*str)
    {
        if (is_charset(*str, charset))
        {
            in_substring = 0;
        }
        else if (!in_substring)
        {
            count++;
            in_substring = 1;
        }
        str++;
    }
    return count;
}

// Function to create a substring from str, starting at start and ending at end
char *create_substring(char *str, int start, int end)
{
    char *substring = malloc((end - start + 1) * sizeof(char));
    if (!substring)
        return NULL;
    int i = 0;
    while (start < end)
    {
        substring[i++] = str[start++];
    }
    substring[i] = '\0';
    return substring;
}

// The main splitting function
char **ft_split(char *str, char *charset)
{
    int substr_count = count_substrings(str, charset);
    char **result = malloc((substr_count + 1) * sizeof(char *)); // +1 for NULL at the end
    if (!result)
        return NULL;

    int i = 0;
    int start = 0;
    int in_substring = 0;

    while (*str)
    {
        if (is_charset(*str, charset))
        {
            if (in_substring)
            {
                result[i] = create_substring(str, start, str - str);
                if (!result[i])
                {
                    // Free previously allocated substrings and return NULL if allocation fails
                    while (i > 0)
                        free(result[--i]);
                    free(result);
                    return NULL;
                }
                i++;
                in_substring = 0;
            }
        }
        else if (!in_substring)
        {
            start = str - str;
            in_substring = 1;
        }
        str++;
    }

    // If the last substring ended before the string finished
    if (in_substring)
    {
        result[i] = create_substring(str, start, str - str);
        if (!result[i])
        {
            // Free previously allocated substrings and return NULL if allocation fails
            while (i > 0)
                free(result[--i]);
            free(result);
            return NULL;
        }
    }

    result[i] = NULL; // End the array with a NULL pointer
    return result;
}
#include <stdio.h>

int main()
{
    char str[] = "Hello, World! How are you?";
    char charset[] = " ,!?";  // Split by space, comma, exclamation mark, and question mark

    char **result = ft_split(str, charset);

    // Print the substrings
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]); // Free each substring
    }
    free(result); // Free the array of pointers

    return 0;
}


*/