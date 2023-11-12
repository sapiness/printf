#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count = 0;

  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      switch (format[i]) {
        case 'c': {
          char c = va_arg(args, int);
          putchar(c);
          count++;
          break;
        }
        case 's': {
          char *str = va_arg(args, char *);
          if (str != NULL) {
            fputs(str, stdout);
            count += strlen(str);
          } else {
            fputs("(null)", stdout);
            count += 6;
          }
          break;
        }
        case '%': {
          putchar('%');
          count++;
          break;
        }
        default: {
          break;
        }
      }
    } else {
      putchar(format[i]);
      count++;
    }
  }

  va_end(args);
  return count;
}
