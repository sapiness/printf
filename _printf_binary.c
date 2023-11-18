#include "main.h"

/**
 * _printf_binary - prints binary representation of an unsigned int
 * @args: va_list containing the unsigned int to be printed
 * Return: number of characters printed
 */

int _printf_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int binary[32]; /*assuming 32-bit integers*/
	int i, count = 0;

	if (num < 0)
	{
		putchar('-');
		abs_num = -num; /*use absolute value for negative numbers*/
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
