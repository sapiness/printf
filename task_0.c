#include "main.h"

int _printf(const char *format, ...) {

	int i,j;
	int count = 0;
	va_list args;
  va_start(args, format);

  if (format == NULL) {
    return -1;
  }

  for (i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      switch (format[i]) {
        case 'c': {
          char c = va_arg(args, int);
          putchr(c);
          count++;
          break;
        }
        case 's': {
          char *str = va_arg(args, char *);
          if (str != NULL) {
            for (j = 0; str[j] != '\0'; j++) {
              putchr(str[j]);
              count++;
            }
          } else {
            for (j = 0; "(null)"[j] != '\0'; j++) {
              putchr("(null)"[j]);
              count++;
            }
          }
          break;
        }
        case '%': {
          putchr('%');
          count++;
          break;
        }
        default: {
          break;
        }
      }
    } else {
      putchr(format[i]);
      count++;
    }
  }

  va_end(args);
  return count;
}
