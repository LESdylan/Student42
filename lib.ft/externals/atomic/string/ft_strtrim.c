#include <stdlib.h>
#include <string.h>

static int is_in_set(char c, const char *set) {
    while (*set) {
        if (c == *set) {
            return 1;
        }
        set++;
    }
    return 0;
}

char *ft_strtrim(const char *s1, const char *set) {
    if (!s1 || !set) {
        return NULL;
    }

    // Trim the leading characters
    while (*s1 && is_in_set(*s1, set)) {
        s1++;
    }

    // Trim the trailing characters
    size_t end = strlen(s1);
    while (end > 0 && is_in_set(s1[end - 1], set)) {
        end--;
    }

    // Create a new string with the trimmed content
    char *result = (char *)malloc(end + 1);
    if (!result) {
        return NULL;
    }
    strncpy(result, s1, end);
    result[end] = '\0';

    return result;
}

// Test function
#include <stdio.h>
int main() {
    const char *str = "  ***Hello, World!***  ";
    const char *set = " *";
    char *trimmed = ft_strtrim(str, set);

    if (trimmed) {
        printf("Trimmed string: '%s'\n", trimmed);
        free(trimmed);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
