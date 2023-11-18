#ifndef MAIN_H
#define MAIN_H

#define MAX_BINARY_DIGITS 32

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
void _print_s(char *str);
int _printf(const char *format, ...);
int putchr(char c);
int _stringoutput(char *str);
int _strlen(char *s);
int _printf_numbers(long int number);
int _printf_binary(va_list args);

#endif
