// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <stdio.h>
#include <string.h>
#define VOWEL_LENGTH 4 // Adjusted to match actual number of vowels

typedef struct no_vowels {
    char letter;
    int number;
} vowels;

vowels vowel[VOWEL_LENGTH];

// Convert vowels in the string to their corresponding numbers
void convert_vowel(char *c) {
    int i, j;
    for (i = 0; c[i] != '\0'; i++) { // Loop through each character in the input string
        for (j = 0; j < VOWEL_LENGTH; j++) { // Check against vowels
            if (c[i] == vowel[j].letter) {
                c[i] = vowel[j].number + '0'; // Replace with corresponding number (as a char)
                break;
            }
        }
    }
    printf("Converted string: %s\n", c); // Print the converted string
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <strings to convert>\n", argv[0]);
        return 1;
    }

    int i;
    int numbers[4] = {6, 3, 1, 0}; // Numbers associated with vowels
    char letters[] = "aeio";       // Letters corresponding to vowels
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Initialize the vowel array
    for (i = 0; i < size; i++) {
        vowel[i].letter = letters[i];
        vowel[i].number = numbers[i];
    }

    // Print vowels and their associated numbers
    for (i = 0; i < size; i++) {
        printf("%c -> %d\n", vowel[i].letter, vowel[i].number);
    }

    // Convert each argument (starting from index 1)
    for (i = 1; i < argc; i++) {
        printf("Original string: %s\n", argv[i]);
        convert_vowel(argv[i]);
    }

    return 0;
}
