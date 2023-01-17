#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int my_putchr(char);
int print_base(size_t, int);
int print_decimal(va_list, char);
int print_string(va_list);
int print_number(va_list, int);
int print_char(va_list);
int print_formatted(va_list, char);
int my_printf(char *restrict, ...);

int my_putchr(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}

int print_base(size_t unslong, int base)
{
    char *c_array = (char *)malloc(sizeof(char));
    int index = 0, count = 0;
    do
    {
        int modulus = unslong % base;
        if (modulus >= 0 && modulus < 10)
            c_array[index] = modulus + '0';
        else
            c_array[index] = 'a' + modulus - 10;
        c_array = realloc(c_array, sizeof(char) + (sizeof(char) * ++index));
        unslong /= base;
    } while (unslong > 0);

    do
    {
        index--;
        count += my_putchr(c_array[index]);
    } while (index);
    free(c_array);
    return count;
}

int print_decimal(va_list ap, char format)
{
    int current = va_arg(ap, int);
    int count = 0;
    if (current < 0)
    {
        current = -current;
        if (format == 'd')
            count += my_putchr('-');
    }
    count += print_base(current, 10);
    return count;
}

int print_string(va_list ap)
{
    char *string = va_arg(ap, char *);
    int count = 0;
    while (*string != '\0')
    {
        char c = *string;
        count += my_putchr(c);
        string++;
    }
    return count;
}

int print_number(va_list ap, int base)
{
    size_t current = va_arg(ap, size_t);
    return print_base(current, base);
}

int print_char(va_list ap)
{
    char current = va_arg(ap, int);
    return my_putchr(current);
}

int print_formatted(va_list ap, char format)
{
    switch (format)
    {
    case 'd':
    case 'u':
        return print_decimal(ap, format);
    case 'o':
        return print_number(ap, 8);
    case 'p':
    case 'x':
        return print_number(ap, 16);
    case 'c':
        return print_char(ap);
    case 's':
        return print_string(ap);
    }
    return 0;
}

int my_printf(char *format, ...)
{
    int total_print = 0;
    va_list ap;
    va_start(ap, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(++format) != '\0')
            total_print += print_formatted(ap, *format);
        else
            total_print += my_putchr(*format);

        if (*format != '\0')
            format++;
    }

    va_end(ap);
    return total_print;
}