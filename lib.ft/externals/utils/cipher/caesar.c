#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char plain[50];
    char r[50];
    unsigned int offset;
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./caesar key\n");
        return 1;
    }

    char *endptr;
    offset = strtoul(argv[1], &endptr, 10);
    if (*endptr != '\0')
    {
        fprintf(stderr, "Err 2: Key must be a valid integer\n");
        return 1;
    }

    printf("plaintext: ");
    if (fgets(plain, sizeof(plain), stdin) == NULL)
    {
        fprintf(stderr, "Err 3: Failed to read plaintext\n");
        return 1;
    }

    size_t len = strlen(plain);
    if (len > 0 && plain[len - 1] == '\n')
    {
        plain[len - 1] = '\0';
    }

    i = 0;
    while (plain[i] != '\0')
    {
        if (isupper(plain[i])) // Majuscules
        {
            r[i] = ((plain[i] - 'A') + offset) % 26 + 'A';
        }
        else if (islower(plain[i])) // Minuscules
        {
            r[i] = ((plain[i] - 'a') + offset) % 26 + 'a';
        }
        else // Caractères non alphabétiques
        {
            r[i] = plain[i];
        }
        i++;
    }
    r[i] = '\0';

    printf("ciphertext: %s\n", r);

    return 0;
}
