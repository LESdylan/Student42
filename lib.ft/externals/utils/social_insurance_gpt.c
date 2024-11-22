#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Fonction pour vérifier la validité du numéro de sécurité sociale
int is_social_number_valid(const char *number) {
    // Vérification du format avec une expression régulière (à la manière de PHP)
    if (strlen(number) != 15) {
        return 0;  // Longueur incorrecte
    }
    
    // Vérification si le premier caractère est '1' ou '2'
    if (number[0] != '1' && number[0] != '2') {
        return 0;  // Sexe incorrect
    }

    // Vérification du mois (position 3 et 4)
    if (!(number[3] == '0' && number[4] >= '1' && number[4] <= '9') && 
        !(number[3] == '1' && number[4] >= '0' && number[4] <= '2')) {
        return 0;  // Mois incorrect
    }

    // Vérification des 10 à 13e caractères (numéro de naissance)
    for (int i = 10; i <= 13; i++) {
        if (!isdigit(number[i])) {
            return 0;  // Numéro de naissance incorrect
        }
    }

    // Extraction des premiers 13 chiffres
    char first_numbers_str[14];
    strncpy(first_numbers_str, number, 13);
    first_numbers_str[13] = '\0';

    long first_numbers = strtol(first_numbers_str, NULL, 10);
    
    // Extraction de la clé de contrôle (derniers 2 chiffres)
    int control_key = atoi(&number[13]);

    // Calcul de la clé de contrôle attendue
    int expected_key = 97 - (first_numbers % 97);

    // Comparaison de la clé attendue et réelle
    return expected_key == control_key;
}

int main() {
    // Tests
    printf("%d\n", is_social_number_valid("369054958815780")); // false (0)
    printf("%d\n", is_social_number_valid("269134958815780")); // false (0)
    printf("%d\n", is_social_number_valid("26914958815780"));  // false (0)
    printf("%d\n", is_social_number_valid("269054958815781")); // false (0)
    printf("%d\n", is_social_number_valid("199095145482285")); // true (1)

    return 0;
}
