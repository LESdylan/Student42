#include <stdio.h>
#include <regex.h>
#include <string.h>

#define BUFFER_SIZE 20

int is_social_number_valid(const char *number) {
    // Expression régulière pour valider le format du numéro de sécurité sociale
    const char *pattern = "^[12][0-9]{2}(0[1-9]|1[0-2])[0-9]{10}$";
    regex_t regex;
    int ret;

    // Compiler l'expression régulière
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        printf("Erreur de compilation de l'expression régulière\n");
        return 0;
    }

    // Vérifier si le numéro correspond au modèle
    ret = regexec(&regex, number, 0, NULL, 0);
    regfree(&regex);  // Libérer la mémoire utilisée par l'objet regex
    if (ret) {
        return 0;  // Le numéro ne correspond pas au format
    }

    return 1;  // Le numéro correspond au format
}

int main(void) {
    char input[BUFFER_SIZE];

    // Entrée de l'utilisateur
    printf("Entrez votre numéro de sécurité sociale: ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        printf("Erreur de lecture\n");
        return 1;
    }

    // Retirer le caractère de nouvelle ligne
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Vérifier la validité du numéro de sécurité sociale
    if (is_social_number_valid(input)) {
        printf("Le numéro de sécurité sociale est valide\n");
    } else {
        printf("Le numéro de sécurité sociale est invalide\n");
    }

    return 0;
}
