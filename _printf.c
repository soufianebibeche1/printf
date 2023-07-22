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
	int printed_chars = 0, i = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			switch (format[i])
			{
				case 'c':
					printed_chars += print_char(args);
					break;
				case 's':
					printed_chars += print_string(args);
					break;
				case 'd':
				case 'i':
					printed_chars += print_int(args);
					break;
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
