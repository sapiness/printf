#include "main.h"
/**
 * _printf_numbers - prints an integer value
 * @number: number to be printed
 * Return: number printed
 */
int _printf_numbers(int number)
{
	int copy, digit, divider = 1, digitCount = 0;

	if (number < 0)
	{
		_putchar('-');
		number = -number;
		digitCount++;
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
