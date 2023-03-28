#include <stdarg.h>
#include <stdio.h>

/**
 *
 *The _printf() function is expected to take a format string and optional arguments and print the formatted output to stdout. It should return the number of characters printed.
 *
 */


int _printf(const char *format, ...)
{
    va_list arg_list;
    int count = 0;

    va_start(arg_list, format);

    // Loop through each character in the format string
    while (*format != '\0') {
        if (*format == '%') {
            // Handle the conversion specifier
            switch (*(++format)) {
                case 'c':
                    // Print a character
                    count += printf("%c", va_arg(arg_list, int));
                    break;
                case 's':
                    // Print a string
                    count += printf("%s", va_arg(arg_list, char *));
                    break;
                case '%':
                    // Print a percent sign
                    count += printf("%%");
                    break;
                default:
                    // Invalid conversion specifier, do nothing
                    break;
            }
        } else {
            // Print any non-% character as is
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(arg_list);

    return count;
}

