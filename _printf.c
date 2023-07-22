#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf
 * @format: is a character string,
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int c, nb_printedchar = 0;
	char *str;
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
				{
					c = va_arg(args, int);
					putchar(c);
					nb_printedchar++;
					break;
				}
				case 's':
				{
					str = va_arg(args, char *);
					while (*str)
					{
						putchar(*str);
						str++;
						nb_printedchar++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					nb_printedchar++;
					break;
				}
				default:
				{
					putchar('%');
					putchar(*format);
					nb_printedchar = nb_printedchar + 2;
					break;
				}
			}
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
