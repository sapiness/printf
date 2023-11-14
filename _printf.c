#include "main.h"

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
}
