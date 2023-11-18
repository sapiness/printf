#include "main.h"
/**
 * _printf_octal - prints an unsigned int in octal format
 * @num: unsigned int to be printed
 * Return: number of characters printed
 */
int _printf_octal(unsigned int num)
{
	int len = 0;

	if (num == 0)
	{
		len += _putchar('0');
	}
	else
	{
		len += _printf_octal(num / 8);
		len += _putchar(num % 8 + '0');
	}

	return (len);
}
