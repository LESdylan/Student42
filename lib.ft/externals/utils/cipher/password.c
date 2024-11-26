/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:20:39 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 13:58:26 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
int valid(char *password);

int main(void)
{
    printf("Enter your password: ");
    char password[50];
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    if (valid(password))
        printf("Your password is valid!\n");
    else
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
}

// TODO: Complete the Boolean function below
int valid(char *password)
{
    int has_lower = 0, has_upper = 0, has_digit = 0, has_symbol = 0;

    // Iterate through each character in the password
    while (*password != '\0')
    {
        if (islower(*password))
            has_lower = 1;
        else if (isupper(*password))
            has_upper = 1;
        else if (isdigit(*password))
            has_digit = 1;
        else if (!isalnum(*password))
            has_symbol = 1;

        // Short-circuit if all criteria are met
        if (has_lower && has_upper && has_digit && has_symbol)
            return 1;

        password++;
    }

    // Return 1 if all conditions are met, otherwise 0
    return 0;
}
