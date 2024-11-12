#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 500

// Structure to store analysis data
typedef struct
{
    unsigned int letter_count;
    unsigned int word_count;
    unsigned int sentence_count;
    float L;
    float S;
} TextAnalysis;

unsigned int ft_strlen(const char *str);
unsigned int ft_isalpha(int c);
unsigned int ft_count_letters(const char *s);
unsigned int ft_count_words(const char *s);
unsigned int ft_count_sentences(const char *s);
float calculate_L(unsigned int letters, unsigned int words);
float calculate_S(unsigned int sentences, unsigned int words);
int compute_coleman_liau_index(float L, float S);
size_t ft_strcspn(const char *s, const char *reject);

TextAnalysis analyze_text(const char *text);

int main()
{
    char *input = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if (input == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    while (1)
    {
        printf("Text: ");
        if (fgets(input, BUFFER_SIZE, stdin) == NULL)
        {
            fprintf(stderr, "Error: Failed to read input.\n");
            free(input);
            return 1;
        }

        input[ft_strcspn(input, "\n")] = 0;

        if (ft_strlen(input) == 0)
        {
            fprintf(stderr, "Error: No text provided. Please enter a valid text.\n");
            continue;
        }

        TextAnalysis analysis = analyze_text(input);
        int grade_level = compute_coleman_liau_index(analysis.L, analysis.S);

        if (grade_level < 1)
            printf("Before Grade 1\n");
        else if (grade_level >= 16)
            printf("Grade 16+\n");
        else
            printf("Grade %d\n", grade_level);

        break;
    }

    free(input);
    input = NULL; // Set to NULL after freeing memory.
    return 0;
}

TextAnalysis analyze_text(const char *text)
{
    TextAnalysis analysis;
    analysis.letter_count = ft_count_letters(text);
    analysis.word_count = ft_count_words(text);
    analysis.sentence_count = ft_count_sentences(text);
    analysis.L = calculate_L(analysis.letter_count, analysis.word_count);
    analysis.S = calculate_S(analysis.sentence_count, analysis.word_count);
    return analysis;
}

int compute_coleman_liau_index(float L, float S)
{
    return (int) round((0.0588 * L) - (0.296 * S) - 15.8);
}

unsigned int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

unsigned int ft_count_letters(const char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        if (ft_isalpha(*s))
            count++;
        s++;
    }
    return count;
}

unsigned int ft_count_words(const char *str)
{
    int in_word = 0;
    int count = 0;

    while (*str != '\0')
    {
        if (ft_isalpha(*str))
        {
            if (in_word == 0)
            {
                count++;
                in_word = 1;
            }
        }
        else if (*str == '\'' || *str == '-' || *str == '_')
        {
            if (ft_isalpha(*(str + 1)))
            {
                str++;
                continue;
            }
            else
            {
                in_word = 0;
            }
        }
        else
        {
            in_word = 0;
        }
        str++;
    }
    return count;
}

unsigned int ft_count_sentences(const char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        if (*s == '.' || *s == '!' || *s == '?')
            count++;
        s++;
    }
    return count;
}

float calculate_L(unsigned int letters, unsigned int words)
{
    if (words == 0)
    {
        fprintf(stderr, "Error: No words found in the text.\n");
        return 0;
    }
    return ((float) letters / words) * 100;
}

float calculate_S(unsigned int sentences, unsigned int words)
{
    if (words == 0)
    {
        fprintf(stderr, "Error: No words found in the text.\n");
        return 0;
    }
    return ((float) sentences / words) * 100;
}

unsigned int ft_strlen(const char *s)
{
    unsigned int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

size_t ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        for (const char *r = reject; *r != '\0'; r++)
        {
            if (s[i] == *r)
            {
                return i;
            }
        }
        i++;
    }
    return i;
}
