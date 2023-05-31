#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move past the '%'

            // Handle the conversion specifiers
            switch (*format)
            {
                case 'c':
                    // Character specifier
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    // String specifier
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    // Print a literal '%'
                    putchar('%');
                    count++;
                    break;
                default:
                    // Invalid specifier, print the character as is
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            // Regular character, print it
            putchar(*format);
            count++;
        }

        format++; // Move to the next character
    }

    va_end(args);

    return count;
}
