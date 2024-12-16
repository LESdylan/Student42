#include "ft_printf.h"
ssize_t ft_write_c(va_list args)
{
    char c = (char)va_arg(args, int);
    return write(1, &c, 1);
}

ssize_t ft_write_str(va_list args)
{
    char *str = va_arg(args, char *);
    ssize_t len = 0;

    if (!str)
        str = "(null)";
    while (*str)
        len += write(1, str++, 1);
    return len;
}

ssize_t ft_write_dec(va_list args)
{
    int n = va_arg(args, int);
    char buf[12]; // Enough to hold -2^31 to 2^31-1
    int len = 0;

    if (n == 0)
        return write(1, "0", 1);
    if (n < 0)
    {
        len += write(1, "-", 1);
        n = -n;
    }
    for (int i = 10; n > 0; i--, len++)
    {
        buf[i] = (n % 10) + '0';
        n /= 10;
    }
    return write(1, buf + 11 - len, len);
}

ssize_t ft_write_int(va_list args)
{
    return ft_write_dec(args); // `%i` is identical to `%d`
}

ssize_t ft_write_uns(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buf[11]; // Enough to hold 2^32-1
    int len = 0;

    if (n == 0)
        return write(1, "0", 1);
    for (int i = 9; n > 0; i--, len++)
    {
        buf[i] = (n % 10) + '0';
        n /= 10;
    }
    return write(1, buf + 10 - len, len);
}

ssize_t ft_write_ptr(va_list args)
{
    uintptr_t n = (uintptr_t)va_arg(args, void *);
    char *base = "0123456789abcdef";
    char buf[17]; // Enough to hold 64-bit pointer in hexadecimal
    ssize_t len = 0;

    if (!n)
        return write(1, "(nil)", 5);
    for (int i = 15; n > 0; i--, len++)
    {
        buf[i] = base[n % 16];
        n /= 16;
    }
    len += write(1, "0x", 2);
    return len + write(1, buf + 16 - len, len);
}

ssize_t ft_write_hex_low(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char *base = "0123456789abcdef";
    char buf[9]; // Enough to hold 32-bit hex number
    int len = 0;

    if (n == 0)
        return write(1, "0", 1);
    for (int i = 7; n > 0; i--, len++)
    {
        buf[i] = base[n % 16];
        n /= 16;
    }
    return write(1, buf + 8 - len, len);
}

ssize_t ft_write_hex_cap(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char *base = "0123456789ABCDEF";
    char buf[9]; // Enough to hold 32-bit hex number
    int len = 0;

    if (n == 0)
        return write(1, "0", 1);
    for (int i = 7; n > 0; i--, len++)
    {
        buf[i] = base[n % 16];
        n /= 16;
    }
    return write(1, buf + 8 - len, len);
}

ssize_t ft_write_percent(va_list args)
{
    (void)args; // Not used
    return write(1, "%", 1);
}
