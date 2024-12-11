#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 45
#define N 26

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *table[N];

unsigned int hash(const char *word)
{
    return (tolower(word[0]) - 'a') % N;
}

bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fprintf(stderr, "The file cannot be read\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) == 1)
    {
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(dict);
            return false;
        }
        strcpy(new_word->word, word);
        unsigned int index = hash(word);
        new_word->next = table[index];
        table[index] = new_word;
    }

    fclose(dict);
    return true;
}

int main(void)
{
    const char *dictionary = "dictionaries/large";

    if (!load(dictionary))
    {
        fprintf(stderr, "Failed to load the dictionary\n");
        return 1;
    }

    printf("Dictionary loaded successfully!\n");

    // Debug: Print hash table contents
    for (int i = 0; i < N; i++)
    {
        printf("Index %d:", i);
        node *cursor = table[i];
        while (cursor != NULL)
        {
            printf(" %s\n", cursor->word);
            cursor = cursor->next;
        }
        printf(" NULL\n");
    }

    return 0;
}
