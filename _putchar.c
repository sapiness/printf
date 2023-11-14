#include "main.h"

/**
  * _putchar - prints one character
  * @c: character
  * Return: success
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
