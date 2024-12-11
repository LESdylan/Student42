#include <stdio.h>
#include <regex.h>

void preg_grep(const char *pattern, const char **array, int array_size) {
    regex_t regex;
    int result;

    // Compile the regular expression
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        printf("Could not compile regex\n");
        return;
    }

    for (int i = 0; i < array_size; i++) {
        result = regexec(&regex, array[i], 0, NULL, 0);
        if (result == 0) {
            printf("Match found: %s\n", array[i]);
        }
    }

    regfree(&regex);
}

int main() {
    const char *pattern = "\\d+";  // Match digits
    const char *array[] = {
        "apple", "100", "orange", "200", "banana", "500"
    };
    int array_size = sizeof(array) / sizeof(array[0]);

    preg_grep(pattern, array, array_size);

    return 0;
}
