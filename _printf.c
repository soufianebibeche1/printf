#include <stdarg.h>
#include "main.h"

/**
 * recursive_printf - Recursive function to handle custom printf
 * @format: The format string
 * @args: The va_list containing the variable arguments
 * Return: Number of characters printed
 */
int recursive_printf(const char *format, va_list args)
{
	int i;
	char *str;
	char ch;

	if (*format == '\0')
		return (0);
	if (*format != '%')
	{
		_putchar(*format);
		return (1 + recursive_printf(format + 1, args));
	}
	format++;
	switch (*format)
	{
		case 'c':
		{
			ch = va_arg(args, int);
			_putchar(ch);
			return (1 + recursive_printf(format + 1, args));
		}
		case 's':
		{
			str = va_arg(args, char*);
			i = 0;

			if (str == NULL)
					str = "(null)";
			while (str[i] != '\0')
			{
					_putchar(str[i]);
					i++;
			}
			return (i + recursive_printf(format + 1, args));
		}
		case '%':
		{
			_putchar('%');
			return (1 + recursive_printf(format + 1, args));
		}
		default:
		{
			_putchar('%');
			_putchar(*format);
			return (2 + recursive_printf(format + 1, args));
		}
	}
}
/**
 * _printf - Custom printf function that handles %c, %s, and %%
 * @format: The format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	printed_chars = recursive_printf(format, args);
	va_end(args);

	return (printed_chars);
}

