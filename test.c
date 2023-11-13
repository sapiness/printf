#include "main.h"

/**
  * _printf - entry point
  * @format: pp
  * Return: oo
  *
  */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format)

		if (format == 'c')
			count += _putchar(va_arg(ap, int));
		else if (format == 's')
			count += _putchar(va_arg(ap, char *));
		else if (format == 'd')
			count += _putchar(va_arg(ap, int), 10);
		else if (format == '%')
			count += _putchar(va_arg(ap, int));
		else
			count += write(1, &format, 1);
	va_end(args)
		return (count);
}
