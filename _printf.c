#include "main.h"
/**
 * _printf - print to stout formatted text
 * @format: format specifier
 * Return: no. of bytes printed
 */

int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;

	if (!format || (format[0] == '%' &&  format[1] == '\0'))
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchr(format[i]);
		}
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			putchr(va_arg(args, int));

		}
		count += 1;
	}
	return (count);
}
