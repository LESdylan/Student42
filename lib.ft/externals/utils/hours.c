#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks;

    // Prompt for number of weeks
    printf("Number of weeks taking CS50: ");
    scanf("%i", &weeks);

    int hours[weeks];

    // Input hours for each week
    for (int i = 0; i < weeks; i++)
    {
        printf("Week %i HW Hours: ", i + 1);
        scanf("%i", &hours[i]);
    }

    char output;
    do
    {
        // Prompt for output type
        printf("Enter T for total hours, A for average hours per week: ");
        //!here I tried to pass directly toupper into scanf but it didn't work.
        //toupper(scanf(" %c", &output)); 
        scanf("%c", &output); // Note the space before %c to consume any leftover newline
        output = toupper(output); // Convert to uppercase
    }
    while (output != 'T' && output != 'A');

    // Display the result
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculate total or average hours
float calc_hours(int hours[], int weeks, char output)
{
    float total = 0;

    // Sum the hours
    for (int i = 0; i < weeks; i++)
        total += hours[i];

    // Return total or average based on output type
    if (output == 'T')
        return (total);
    else if (output == 'A')
        return (total / weeks);

    return (0); // Default return (should never be reached)
}
