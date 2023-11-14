#include "main.h"
<<<<<<< HEAD
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
=======

/**
 * _printf - prints formatted string
 * @format: format string
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len = 0;

	va_start(args, format);

	if (!format)
	{
		va_end(args);
		return (-1);
	}

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				len += _stringoutput(va_arg(args, char *));
			else if (format[i] == '%')
				len += _putchar('%');
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(args);
	return (len);
>>>>>>> 3916427505883ad407bc325adf7faf134ce898ee
}
