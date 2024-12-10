/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:31:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:31:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void write_str(const char *str) {
    write(1, str, strlen(str));
}

void write_char(char c) {
    write(1, &c, 1);
}

void write_int(int n) {
    char buffer[50];
    int i = 0;
    if (n == 0) {
        write_char('0');
        return;
    }
    if (n < 0) {
        write_char('-');
        n = -n;
    }
    while (n > 0) {
        buffer[i++] = '0' + (n % 10);
        n /= 10;
    }
    for (int j = i - 1; j >= 0; j--) {
        write_char(buffer[j]);
    }
}

void write_hex(unsigned int n, int uppercase) {
    char hex_chars[] = "0123456789abcdef";
    if (uppercase) {
        for (int i = 0; i < 16; i++) {
            if (hex_chars[i] >= 'a' && hex_chars[i] <= 'f') {
                hex_chars[i] -= 32; // Convert to uppercase
            }
        }
    }

    char buffer[50];
    int i = 0;
    if (n == 0) {
        write_char('0');
        return;
    }
    while (n > 0) {
        buffer[i++] = hex_chars[n % 16];
        n /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        write_char(buffer[j]);
    }
}

void write_float(double f) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%.6f", f);
    write_str(buffer);
}

void write_pointer(void *ptr) {
    write_str("0x");
    write_hex((unsigned long)ptr, 0);
}

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    const char *ptr = format;
    char ch;
    int i;
    unsigned int u;
    char *str;
    double f;
    void *p;
    
    while (*ptr != '\0') {
        if (*ptr == '%' && *(ptr + 1) != '\0') {
            ptr++; // Skip '%' character
            switch (*ptr) {
                case 'd': // Integer
                case 'i':
                    i = va_arg(args, int);
                    write_int(i);
                    break;
                case 's': // String
                    str = va_arg(args, char*);
                    write_str(str);
                    break;
                case 'c': // Character
                    ch = (char) va_arg(args, int); // Promoted to int for variadic functions
                    write_char(ch);
                    break;
                case 'x': // Hexadecimal (lowercase)
                    u = va_arg(args, unsigned int);
                    write_hex(u, 0);
                    break;
                case 'X': // Hexadecimal (uppercase)
                    u = va_arg(args, unsigned int);
                    write_hex(u, 1);
                    break;
                case 'f': // Floating point
                    f = va_arg(args, double);
                    write_float(f);
                    break;
                case 'p': // Pointer
                    p = va_arg(args, void*);
                    write_pointer(p);
                    break;
                default:
                    write_char('%');
                    write_char(*ptr);
                    break;
            }
        } else {
            write_char(*ptr);
        }
        ptr++;
    }
    
    va_end(args);
}

int main() {
    int x = 42;
    char c = 'A';
    char *str = "Hello, world!";
    double f = 3.14159;
    
    my_printf("Integer: %d\n", x);
    my_printf("String: %s\n", str);
    my_printf("Character: %c\n", c);
    my_printf("Hexadecimal: %x\n", x);
    my_printf("Hexadecimal (uppercase): %X\n", x);
    my_printf("Floating point: %f\n", f);
    my_printf("Pointer: %p\n", &x);
    
    return 0;
}
