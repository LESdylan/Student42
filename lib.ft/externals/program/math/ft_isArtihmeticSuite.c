#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
/**
 * check the index of all the arithmetic function
 */
// Fonction prototype pour la génération de termes
typedef int (*GenerateFunction)(int);

// Fonction pour remplacer 'n' par une valeur donnée dans une chaîne
void replace_n_with_value(const char *expression, int value, char *output) {
    char value_str[20];
    sprintf(value_str, "%d", value); // Convertit la valeur en chaîne
    int j = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == 'n') {
            // Ajoute la valeur à la place de 'n'
            for (int k = 0; value_str[k] != '\0'; k++) {
                output[j++] = value_str[k];
            }
        } else {
            // Copie les autres caractères
            output[j++] = expression[i];
        }
    }
    output[j] = '\0'; // Terminer la chaîne
}


// Fonction pour évaluer une expression simple avec `n`
int evaluate_expression(const char *expression, int n) {
    char evaluated_expr[100];
    replace_n_with_value(expression, n, evaluated_expr);

    char command[150];
    sprintf(command, "echo '%s' | bc", evaluated_expr); // Utiliser bc pour l'évaluation

    FILE *fp = popen(command, "r"); // Exécuter la commande et lire le résultat
    if (!fp) {
        fprintf(stderr, "Erreur lors de l'évaluation de l'expression.\n");
        exit(EXIT_FAILURE);
    }

    int result;
    fscanf(fp, "%d", &result); // Lire le résultat entier
    pclose(fp);

    return result;
}

// Fonction pour générer une suite basée sur une expression utilisateur
// Exemple de suite linéaire pour tester : 2*n + 3
int generate_arithmetic(int n) {
    static char expression[100];
    static bool initialized = false;

    if (!initialized) {
        printf("Veuillez entrer une expression pour générer la suite (ex: 2*n+3): ");
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = '\0'; // Nettoyer l'entrée
        initialized = true;
    }

    return evaluate_expression(expression, n);
}

// Générer une suite basée sur une fonction donnée
int* calc(GenerateFunction formula, int size) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Erreur : allocation mémoire échouée !\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        array[i] = formula(i); // Appel de la fonction utilisateur
    }

    return array;
}

// Vérifie si une suite est arithmétique
int is_reccurent(int suite[], int size, int* reason) {
    if (size < 2) {
        fprintf(stderr, "Erreur : la suite doit avoir au moins deux termes.\n");
        return 1; // Erreur
    }

    // Calculer la première différence (raison)
    int r = suite[1] - suite[0];
    for (int i = 1; i < size; i++) {
        if (suite[i] - suite[i - 1] != r) {
            fprintf(stderr, "La suite n'est pas arithmétique.\n");
            return 2; // Erreur
        }
    }

    *reason = r; // Si la suite est arithmétique, assigner la raison
    return 0; // Succès
}


int main() {
    int size = 30; // Taille de la suite
    int reason;

    printf("Génération d'une suite arithmétique...\n");

    // Générer une suite en utilisant une fonction génératrice
    int* suite = calc(generate_arithmetic, size);

    // Afficher la suite générée
    printf("Suite générée : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", suite[i]);
    }
    printf("\n");

    // Vérifier si la suite est arithmétique
    if (is_reccurent(suite, size, &reason) == 0) {
        printf("La suite est arithmétique avec une raison de %d.\n", reason);
    } else {
        printf("La suite n'est pas arithmétique.\n");
    }

    // Libérer la mémoire
    free(suite);

    return 0;
}
