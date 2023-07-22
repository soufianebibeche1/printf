#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf
 * @format: is a character string,
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int nb_printedchars = 0;
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					nb_printedchars += print_char(args);
					break;
				case 's':
					nb_printedchars += print_string(args);
					break;
				case '%':
					_putchar('%');
					nb_printedchars++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					nb_printedchars += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			nb_printedchars++;
		}
		i++;
	}
	va_end(args);
	return (nb_printedchars);
}
