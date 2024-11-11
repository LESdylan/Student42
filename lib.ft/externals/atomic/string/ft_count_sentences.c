/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sentences.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:04:01 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/11 15:09:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int ft_count_sentences(char *s)
{
    int count = 0;
    bool in_sentence = false;

    while (*s != '\0')  
    {
        if (*s == '.' && !in_sentence)  // Only count the first period in a sequence
        {
            count++;
            in_sentence = true;  // Mark that we are now in a sentence-ending state
        }
        else if (*s != '.') 
        {
            in_sentence = false;  // If not a period, we are no longer in a sentence-ending state
        }
        s++;
    }
    return count;
}

int main()
{
    char *text = "Hello... world. How are you? I'm fine.";
    printf("Number of sentences: %d\n", ft_count_sentences(text));  // Output the sentence count
    return 0;
}

