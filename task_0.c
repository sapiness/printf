#include "main.h"

int _printf(const char *format, ...) {
  va_list args;
  va_start(args, format);

  if (format == NULL) {
    return -1;
  }

  int count = 0;

  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      switch (format[i]) {
        case 'c': {
          char c = va_arg(args, int);
          _putchar(c);
          count++;
          break;
        }
        case 's': {
          char *str = va_arg(args, char *);
          if (str != NULL) {
            _fputs(str, stdout);
            count += _strlen(str);
          } else {
            _fputs("(null)", stdout);
            count += 6;
          }
          break;
        }
        case '%': {
          _putchar('%');
          count++;
          break;
        }
        default: {
          break;
        }
      }
    } else {
      _putchar(format[i]);
      count++;
    }
  }

  va_end(args);
  return count;
}
