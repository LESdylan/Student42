#include <stdlib.h>
#include <string.h>

char *ft_substr(const char *s, unsigned int start, size_t len) {
    if (!s) {
        return NULL;
    }

    size_t s_len = strlen(s);
    if (start >= s_len) {
        return strdup("");  // Return an empty string if start is out of range
    }

    size_t substr_len = len;
    if (start + len > s_len) {
        substr_len = s_len - start;  // Adjust length if it exceeds string size
    }

    char *substr = (char *)malloc(substr_len + 1);
    if (!substr) {
        return NULL;
    }

    strncpy(substr, s + start, substr_len);
    substr[substr_len] = '\0';  // Null-terminate the substring

    return substr;
}

// Test function
#include <stdio.h>
int main() {
    const char *str = "Hello, World!";
    char *substr = ft_substr(str, 7, 5);

    if (substr) {
        printf("Substring: '%s'\n", substr);
        free(substr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
