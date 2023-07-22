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
	char *str;
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
				putchar(va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				while (*str != '\0')
				{
    					putchar(*str);
    					str++;
				}
				break;
			case '%':
				putchar('%');
				nb_printedchar++;
				break;
			default:
				putchar(*format);
				break;
			}
			nb_printedchar++;
		}
		else
		{
			putchar(*format);
			nb_printedchar++;
		}
		format++;
	}
	va_end(args);
	return (nb_printedchar);
}
