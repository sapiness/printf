#include "main.h"

/**
  * _stringoutput - print the entire string   * str: string charaters
  * @str: character
  * Return: the entire string
  */

int _stringoutput(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		len = write(1, "(null)", 6);
	}
	else
	{
		len = _strlen(str);
		write(1, str, len);
	}
	return (len);
}
