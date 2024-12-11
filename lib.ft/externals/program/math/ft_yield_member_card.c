#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[50];
    char offer[50];
    printf("Please enter the given price of the membership: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        fprintf(stderr, "Error 1: the input is empty.");
        return 1;
    }
    printf("Please enter the offer in percentage: ");
    if (fgets(offer, sizeof(offer), stdin) == NULL)
    {
        fprintf(stderr, "Error 1: the input is empty.");
        return 1;
    }

    int int_input = atoi(input);
    int int_offer = atoi(offer);

    if (int_offer == 0)
    {
        fprintf(stderr, "Error: Offer percentage cannot be zero.");
        return 1;
    }

    float result = int_input / (int_offer / 100.0);
    printf("The discounted price is: %.0f\n", result);
    return 0;
}