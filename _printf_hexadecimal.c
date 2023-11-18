#include "main.h"
/**
 * _printf_hexadecimal - prints an unsigned int in hexadecimal format
 * @num: unsigned int to be printed
 * @uppercase: 1 for uppercase letters, 0 for lowercase
 * Return: number of characters printed
 */
int _printf_hexadecimal(unsigned int num, int uppercase)
{
	int len = 0;
	char hex[] = "0123456789abcdef";

	if (uppercase)
		hex[10] = 'A';

	if (num == 0)
	{
		len += _putchar('0');
	}
	else
	{
		len += _printf_hexadecimal(num / 16, uppercase);
		len += _putchar(hex[num % 16]);
	}

	return (len);
}
