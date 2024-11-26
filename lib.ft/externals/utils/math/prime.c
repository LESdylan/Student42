#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool prime(int number);

int main(void)
{
    int min, max;

    // Obtenir les bornes de l'intervalle
    do
    {
        printf("Minimum: ");
        scanf("%d", &min);
    }
    while (min < 1);

    do
    {
        printf("Maximum: ");
        scanf("%d", &max);
    }
    while (min >= max);

    // Parcourir l'intervalle et afficher les nombres premiers
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}

// Fonction pour vérifier si un nombre est premier
bool prime(int number)
{
    if (number <= 1) 
        return false; // Les nombres <= 1 ne sont pas premiers
    
    for (int i = 2; i <= number; i++) // Vérifie jusqu'à sqrt(number)
    {
        if (number % i == 0) 
            return false; // Trouvé un diviseur, donc pas premier
    }

    return true; // Aucun diviseur trouvé, donc premier
}
