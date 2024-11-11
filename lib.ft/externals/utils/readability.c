#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototypes
unsigned int ft_isalpha(int c);
unsigned int ft_count_letters(const char *s);
unsigned int ft_count_words(const char *s);
unsigned int ft_count_sentences(const char *s);
float calculate_L(const char *s);
float calculate_S(const char *s);
int compute_coleman_liau_index(float L, float S);

int main()
{
    char input[500];

    while(1)
    {
        printf("Text: ");
        fgets(input, sizeof(input), stdin);

        // Enlever le caractère de nouvelle ligne ajouté par fgets
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0)
        {
            fprintf(stderr, "Error: No text provided. Please enter a valid text.\n");
            continue;  // Demander à l'utilisateur d'entrer du texte à nouveau
        }

        // Calcul des moyennes L et S
        float L = calculate_L(input);
        float S = calculate_S(input);

        // Calcul de l'index de lisibilité
        int grade_level = compute_coleman_liau_index(L, S);

        // Affichage du niveau de lisibilité
        if (grade_level < 1)
            printf("Before Grade 1\n");
        else if (grade_level >= 16)
            printf("Grade 16+\n");
        else
            printf("Grade Level: %d\n", grade_level);

        break;  // Sortir de la boucle après avoir effectué le calcul
    }

    return 0;
}
// Calcul de l'index de lisibilité
int compute_coleman_liau_index(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return (int)round(index);
}

// Compte le nombre de lettres
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

// Vérifie si un caractère est alphabétique
unsigned int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// Compte le nombre de mots
unsigned int ft_count_words(const char *s)
{
    int count = 0;
    int in_word = 0;

    while (*s != '\0')
    {
        if (ft_isalpha(*s))
        {
            if (in_word == 0)
            {
                count++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
        s++;
    }
    return count;
}

// Compte le nombre de phrases
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

// Calcul de la moyenne des lettres par 100 mots
float calculate_L(const char *s)
{
    int letters = ft_count_letters(s);
    int words = ft_count_words(s);

    // Gestion d'erreur: éviter la division par zéro si aucun mot n'est trouvé
    if (words == 0) {
        fprintf(stderr, "Erreur: Aucun mot trouvé dans le texte.\n");
        return 0;  // Retourne 0 pour éviter une division par zéro
    }

    return (float)letters / words * 100;
}

// Calcul de la moyenne des phrases par 100 mots
float calculate_S(const char *s)
{
    int sentences = ft_count_sentences(s);
    int words = ft_count_words(s);

    // Gestion d'erreur: éviter la division par zéro si aucun mot n'est trouvé
    if (words == 0) {
        fprintf(stderr, "Erreur: Aucun mot trouvé dans le texte.\n");
        return 0;  // Retourne 0 pour éviter une division par zéro
    }

    return (float)sentences / words * 100;
}
