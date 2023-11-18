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

	if (!format || (format[0] == '%' && !format[1]) ||
			(format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				len += _stringoutput(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				len += _printf_numbers(va_arg(args, int));
			else if (format[i] == 'b')
				len += _printf_binary(args);
			else if (format[i] == 'u')
				len += _printf_unsigned_int(va_arg(args, unsigned int));
			else if (format[i] == 'o')
				len += _printf_octal(va_arg(args, unsigned int));
			else if (format[i] == 'x' || format[i] == 'X')
				len += _printf_hexadecimal(va_arg(args, unsigned int), format[i] == 'X');
			else if (format[i] == '%')
				len += _putchar('%');
			else
				len += _putchar('%') + _putchar(format[i]);
		}
		else
			len += _putchar(format[i]);
	}
	va_end(args);
	return (len);
}
