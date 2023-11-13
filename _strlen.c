#include "main.h"

/**
  * _strlen - returns the length of a string
  *
  * @s: Function parameter
  *
  * Return: Length
  */
int _strlen(char *s)
{
	int lnt = 0;

	if (*s)
	{
	lnt++;
	lnt += _strlen(s + 1);
	}
	return (lnt);
}
