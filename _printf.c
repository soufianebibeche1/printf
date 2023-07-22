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
	int nb_printedchar = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				nb_printedchar += print_char(args);
				break;
			case 's':
				nb_printedchar += print_string(args);
				break;
			case '%':
				_putchar('%');
				nb_printedchar++;
				break;
			default:
				_putchar('%');
				_putchar(*format);
				nb_printedchar += 2;
				break;
			}
			nb_printedchar++;
		}
		else
		{
			_putchar(*format);
			nb_printedchar++;
		}
		format++;
	}
	va_end(args);
	return (nb_printedchar);
}
