#include "main.h"

/**
 * _printf_binary - prints binary representation of an unsigned int
 * @args: va_list containing the unsigned int to be printed
 * Return: number of characters printed
 */

int _printf_binary(va_list args)
{
	int binary[32];

	int num, i, count = 0;

	num = va_arg(args, unsigned int);

	if (num == 0)
	{
		_putchar('b');
		count++;
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num; /*use absolute value for negative numbers*/
		count++;
	}

	/*Convert decimal to binary*/
	for (i = 0; num > 0; i++)
	{
		binary[i] = num % 2;
		num = num / 2;
	}

	/*Print binary representation in reverse order*/
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		count++;
	}

	return (count);
}
