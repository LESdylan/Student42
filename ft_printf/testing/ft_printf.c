/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:30:25 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 13:17:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_printf.h"

int main()
{
    // Variables pour les différents types
    char var1 = 'A';                    // Caractère
    char *str = "Hello, World!";        // Chaîne de caractères
    int var2 = 123;                     // Entier
    unsigned int var3 = 456;            // Entier non signé
    int var4 = -789;                    // Entier négatif
    unsigned int var5 = 255;            // Hexa (non signé)
    void *ptr = &var4;                  // Pointeur
    float myFloat = 19.99;              // Nombre à virgule flottante

    // Test des différents formats

    // Caractère
    ft_printf("Caractère : %c\n", var1);

    // Chaîne de caractères
    ft_printf("Chaîne : %s\n", str);

    // Entiers (d et i)
    ft_printf("Entier (d) : %d\n", var2);
    ft_printf("Entier (i) : %i\n", var2);
    ft_printf("Entier négatif (d) : %d\n", var4);

    // Entier non signé (u)
    ft_printf("Entier non signé (u) : %u\n", var3);

    // Hexadecimal (x et X)
    ft_printf("Hexa (x) : %x\n", var5);
    ft_printf("Hexa (X) : %X\n", var5);

    // Octal (o)
    ft_printf("Octal : %o\n", var3);

    // Pointeur (p)
    ft_printf("Pointeur : %p\n", ptr);

    // Affichage du caractère '%' littéral
    ft_printf("Caractère %% : %%\n");

    // Nombre à virgule flottante (f) -- tu devras implémenter ft_write_float si tu veux le supporter
    // Si tu as ajouté une gestion pour le format %f, tu peux tester ici
    // ft_printf("Nombre flottant : %f\n", myFloat);

    // Test de largeur et précision
    ft_printf("Largeur 10 avec précision 2 : %.2f\n", myFloat); // Exemple de largeur et précision pour un float
    //variable declarations
    //char var1 = 120;
    //short int var2 = 2024;
    //int var3 = 95;
    //long int var4 = 212;
    //long long int var5 = 1200L;
    //int value = 1024;
    //float myFloat = 19.99;
//
    ////! SPECIFIED FORMATTER
    ////TODO:Specifica Case
    //ft_printf("%hhd %hd %d %ld %lld", var1, var2, var3, var4, var5);
    //ft_printf("d = %d \t i = %i \t unsigned = %u \n", value);  // Integer
//
    //
    ////TODO:Manipulation of based system value
    //ft_printf( "%o \n", value);    // Octal
    //ft_printf( "%x \n", value);    // Hexadecimal
    //ft_printf("%#o \n", value);    // Octal with "0" prefix
    //ft_printf("%#X \n", value);    // Uppercase hexadecimal with "0X" prefix
    //
    ////TODO:manipulation of float numbers
    //ft_printf("%f \n", myFloat);       // Floating point
    //ft_printf("lowercase :%a \t uppercase :%A", myFloat);  //hexadecimal floating point number
    //ft_printf("%e \n", myFloat);       // Scientific
    //ft_printf("%g \n", myFloat);       // Optimal
    //ft_printf("%.2f \n", myFloat);     // 2 decimal digits
    //ft_printf("%8.2f \n", myFloat);    // 8 characters wide and 2 decimal digits
    //ft_printf("%08.2f \n", myFloat);   // zero-padded 8 characters wide and 2 decimal digits
    //
    ////TODO:Manipulation of strings, memory, characters
    //char myString[20] = "Hello World!\0";
    //int memorySize = sizeof(myString);
    //int stringSize;
    //ft_printf("%s%n\n", myString, &stringSize);  // Using %n to store the number of characters printed
    //ft_printf("Memory size: %d\n", memorySize);
    //ft_printf("String size: %d\n", stringSize);

}