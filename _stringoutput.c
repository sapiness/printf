#include "main.h"

/**
  * _stringoutput - print the entire string   * str: string charaters
  * return: the entire string
  */

int _stringoutput(char *str)
{
	write(1, str, _strlen(str));
 	return(_strlen(str));
}
