#include "main.h"
/**
 * _printf_numbers - prints an integer value
 * description: printing
 * @number: jjj
 * Return: hhhh
 */
int _printf_numbers(int number)
{
	int copy, digit, divider = 1, digitCount = 0;

	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}

	copy = number;

	while (copy >= 10)
	{
		divider *= 10;
		copy /= 10;
	}

	while (divider > 0)
	{
		digit = number / divider;
		_putchar(digit + '0');
		number %= divider;
		divider /= 10;
		digitCount++;
	}

	return (digitCount);
}

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
	char *str;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					len += write(1, "(null)", 6);
				else
					len += _stringoutput(str);
			}
			else if (format[i] == '%')
				len += _putchar('%');
			else
			{
				len += _putchar('%');
				len += _putchar(format[i]);
			}
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
