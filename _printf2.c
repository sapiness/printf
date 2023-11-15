#include "main.h"
/**
  *_printf - prints an integer value
  * description: printing
  * @number: jjj
  * Return: hhhh
  */
int _printf(int number)
{
	int copy, divider = 1, digitCount = 0;

	if (number == INT_MIN)
	{
		_putchar('-');
		number = -(number + 1);
	}
	else if (number < 0)
	{
		_putchar('-');
		number = -number;
	}

	(copy = number);

	while (copy >= 10)
	{
		divider *= 10;
		copy /= 10;
	}

	while (divider > 0)
	{
		int digit = number / divider;

		_putchar(digit + '0');
		number %= divider;
		divider /= 10;
		digitCount++;
	}

	return (digitCount);
}
