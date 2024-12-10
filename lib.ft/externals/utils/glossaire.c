/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossaire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:17:18 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/05 16:17:22 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PEOPLE 100
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

// Structure représentant un résident
typedef struct
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char pnumber[MAX_PHONE_LENGTH];
} resident;

resident residents[MAX_PEOPLE];
int people_count;

// Déclaration de la fonction de validation de l'email
int is_valid_email(const char *email);
// Déclaration de la fonction de validation du numéro de téléphone
int is_valid_phone_number(const char *pnumber);
// Déclaration de la fonction de saisie des informations d'un résident
void enter_resident_info(resident *r);
int create_file(void);
int main(void)
{
    // Demander combien de résidents
    printf("How many residents: ");
    if (scanf("%d", &people_count) != 1 || people_count <= 0 || people_count > MAX_PEOPLE)
    {
        fprintf(stderr, "Invalid number of residents.\n");
        return 1;
    }

    // Vider le tampon après scanf pour ne pas interférer avec fgets
    getchar();

    // Collecter les informations des résidents
    for (int i = 0; i < people_count; i++)
    {
        printf("\n--- Resident %d ---\n", i + 1);
        enter_resident_info(&residents[i]);
    }

    // Afficher toutes les informations des résidents
    printf("\n--- Residents Information ---\n");
    for (int i = 0; i < people_count; i++)
    {
        printf("Name: %s, Email: %s, Phone: %s\n", residents[i].name, residents[i].email, residents[i].pnumber);
    }
    create_file();
    return 0;
}

// Fonction pour vérifier si un email est valide
int is_valid_email(const char *email)
{
    int at_sign = 0, dot_sign = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            at_sign++;
        if (email[i] == '.')
            dot_sign++;
    }
    return (at_sign == 1 && dot_sign >= 1); // Doit avoir un '@' et au moins un '.'
}

// Fonction pour vérifier si un numéro de téléphone est valide
int is_valid_phone_number(const char *pnumber)
{
    if (strlen(pnumber) < 10 || strlen(pnumber) > 15) 
        return 0;

    for (int i = 0; pnumber[i] != '\0'; i++)
    {
        if (!isdigit(pnumber[i])) // Vérifie si tous les caractères sont des chiffres
            return 0;
    }
    return 1;
}

// Fonction pour entrer les informations d'un résident avec validation
void enter_resident_info(resident *r)
{
    // Saisie du nom
    do
    {
        printf("Enter the resident's name (1-99 characters): ");
        fgets(r->name, MAX_NAME_LENGTH, stdin);
        r->name[strcspn(r->name, "\n")] = '\0'; // Enlever le '\n'

        if (strlen(r->name) == 0)
            printf("Name cannot be empty. Please enter a valid name.\n");

    } while (strlen(r->name) == 0); // Répéter si le nom est vide

    // Saisie de l'email avec validation
    do
    {
        printf("Enter the resident's email: ");
        fgets(r->email, MAX_EMAIL_LENGTH, stdin);
        r->email[strcspn(r->email, "\n")] = '\0'; // Enlever le '\n'

        if (!is_valid_email(r->email))
            printf("Invalid email format. Please enter a valid email.\n");

    } while (!is_valid_email(r->email)); // Répéter si l'email n'est pas valide

    // Saisie du numéro de téléphone avec validation
    do
    {
        printf("Enter the resident's phone number (10-15 digits): ");
        fgets(r->pnumber, MAX_PHONE_LENGTH, stdin);
        r->pnumber[strcspn(r->pnumber, "\n")] = '\0'; // Enlever le '\n'

        if (!is_valid_phone_number(r->pnumber))
            printf("Invalid phone number. It should only contain digits and be between 10 and 15 characters long.\n");

    } while (!is_valid_phone_number(r->pnumber)); // Répéter si le numéro est invalide
}

int create_file(void)
{
    FILE * filePointer;

    //open a file in write mode
    filePointer = fopen("Example.txt", "w");
    if(filePointer == NULL)
    {
        printf("failed to create teh file.\n");
        return 1;
    }
    
    int i;
    
    i = -1;
    while(++i < people_count)
    {
        fprintf(filePointer, "%s, %s, %s.\n", residents[i].name,residents[i].email, residents[i].pnumber);
    }
    
    fclose(filePointer);
    printf("File created and text written successfully.\n");
}