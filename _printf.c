#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i, nb_printedchar = 0;
	va_list args;

	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			switch (format[i])
			{
				case 'c':
					nb_printedchar = nb_printedchar + print_char(args);
					break;
				case 's':
					nb_printedchar = nb_printedchar + print_string(args);
					break;
				case 'd':
				case 'i':
					nb_printedchar = nb_printedchar + print_int(args);
					break;
				case '%':
					_putchar('%');
					nb_printedchar++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					nb_printedchar = nb_printedchar + 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			nb_printedchar++;
		}
	}

	va_end(args);

	return (nb_printedchar);
}
