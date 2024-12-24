/**Not Finished*/
//formula ((people - 2)%side_of_middle_table) == 0

#include <stdio.h>
#include <stdlib.h>

void print_possible_table_arrangements(int people) {
    printf("\nFor %d people, the possible table arrangements are:\n", people);
    int found = 0;

    for (int sides = 4; sides <= 8; sides++) {
        int per_extremity = sides - 1;   // Places on a table at the extremity
        int per_middle = sides - 2;     // Places on a table in the middle

        // Minimum people required for 1 table
        int min_people = 2 * per_extremity + per_middle; // Extremities + 1 middle

        if (people < min_people) {
            continue; // Skip if the people count is less than the minimum needed
        }

        // Calculate the number of tables
        int middle_people = people - 2 * per_extremity; // Remaining people for middle tables
        int middle_tables = (middle_people + per_middle - 1) / per_middle; // Round up to full tables
        int total_tables = middle_tables + 2; // 2 for the extremities

        // Print results
        found = 1;
        printf("Table Type: ");
        switch (sides) {
            case 4: printf("Square"); break;
            case 5: printf("Pentagon"); break;
            case 6: printf("Hexagon"); break;
            case 7: printf("Heptagon"); break;
            case 8: printf("Octagon"); break;
        }
        printf(" (sides: %d) - Total tables needed: %d\n", sides, total_tables);
    }

    if (!found) {
        printf("No table arrangements are possible for %d people with the given table types.\n", people);
    }
}

int main() {
    while (1) {
        int people;

        // Prompt for input
        printf("\nEnter the number of people to seat (or 0 to exit): ");
        scanf("%d", &people);

        // Exit condition
        if (people == 0) {
            printf("Exiting the program.\n");
            break;
        }

        if (people <= 2) {
            printf("The number of people must be greater than 2.\n");
            continue;
        }

        // Display possible table arrangements
        print_possible_table_arrangements(people);

        // Ask if the user wants to continue
        char choice;
        printf("\nDo you want to try another number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("Exiting the program.\n");
            break;
        }
    }

    return 0;
}
