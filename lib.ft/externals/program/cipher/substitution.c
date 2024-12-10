#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int has_duplicates(const char *key) {
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (tolower(key[i]) == tolower(key[j])) {
                return 1;
            }
        }
    }
    return 0; 
}

int main(int argc, char **argv) {
    // Vérification du nombre d'arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    if (strlen(key) != 26) {
        fprintf(stderr, "Error: The key must contain exactly 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            fprintf(stderr, "Error: The key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    if (has_duplicates(key)) {
        fprintf(stderr, "Error: The key must not contain duplicate characters.\n");
        return 1;
    }

    char input[50];
    printf("plaintext: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read plaintext.\n");
        return 1;
    }

    // Supprimer le caractère '\n' s'il est présent
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Création du tableau de substitution
    char map[26];
    for (int i = 0; i < 26; i++) {
        map[i] = toupper(key[i]); // Stocker la clé en majuscules
    }

    // Chiffrement du texte
    char ciphertext[50];
    for (int i = 0; i < len; i++) {
        if (isupper(input[i])) {
            ciphertext[i] = map[input[i] - 'A'];
        } else if (islower(input[i])) {
            ciphertext[i] = tolower(map[input[i] - 'a']);
        } else {
            ciphertext[i] = input[i]; // Garder les caractères non alphabétiques inchangés
        }
    }
    ciphertext[len] = '\0'; // Terminer la chaîne

    // Afficher le texte chiffré
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}