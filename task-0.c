#include "main.h"

/**
  * _printf - entry point
  * @format: JJ
  * Return: LL
  */

int _printf(const char *format, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				write(1, str, strlen(str));
			}
			else if (format[i] == '%')
			{
				write(1, str, strlen(str));
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
	}

	va_end(args);

	return (0);
}
