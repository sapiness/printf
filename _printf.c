#include "main.h"
/**
  * _printf - prints string
  * @format: character passed
  * Return: string length
  */
int _printf(const char *format, ...)
{
	int i, len = 0;
	char *str;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1); /*You may want to choose a proper error code*/
	}
	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == 'c')
		{
			char c = va_arg(args, int); /*Read the next argument as a char*/

			_putchar(c);
			len++;
		}
		else if (format[i] == 's')
		{
			str = va_arg(args, char *); /*Read the next argument as a string*/
			len += _stringoutput(str);
		}
		else if (format[i] == '%')
		{
			_putchar('%');
		}
	}
	else
	{
		write(1, &format[i], 1);
		len++;
	}
	}
	va_end(args);
	return (len);
}
