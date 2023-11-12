#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    if (format == NULL)
        return -1;

    int count = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                if (str != NULL)
                    count += write(1, str, strlen(str));
                else
                    count += write(1, "(null)", 6);
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
    }

    va_end(args);

    return count;
}
