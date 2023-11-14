#include "main.h"

/**
 * putchr - prints a character
 * @c: input
 * Return: 1
 */

int putchr(char c)
{
	return (write(1, &c, 1));
}
