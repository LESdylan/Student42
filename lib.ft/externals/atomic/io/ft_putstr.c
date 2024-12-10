#include <stdio.h>

void putstr(const char *str) {
    if (!str) return; // Handle null input
    while (*str) {
        putchar(*str);
        str++;
    }
}

// Test function
int main() {
    putstr("Hello, World!\n");
    return 0;
}
