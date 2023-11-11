#include "main.h"

int _printf(const char *format, ...)
{
	int i;
    va_list args;
    va_start(args, format);

    if (format == NULL)
    {
        va_end(args);
        return -1; /*You may want to choose a proper error code*/
    }

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(args, int); /*Read the next argument as a char*/
                write(1, &c, 1);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *); /*Read the next argument as a string*/
                write(1, str, strlen(str));
            }
            /*Add more cases for other format specifiers as needed*/
        }
        else
        {
            write(1, &format[i], 1);
        }
    }

    va_end(args);

    return 0; /*Return success or an appropriate value*/
}
