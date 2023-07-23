#include "main.h"

/**
 * convertX - Custom printf functioni
 * that handles specifier like %c, %s, and % ...
 * @format: The format string
 * @spec_lst: array of format specifiers
 * @args: arguments passed to _printf.
 * Return: Number of characters printed
 */
int convertX(const char *format, specifier_handler spec_lst[], va_list args)
{
	int i, j, temp, nb_printedchars;

	nb_printedchars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		/* check if the character equal to % symbol of a specifier */
		if (format[i] == '%')
		{
			/*loop inside the specifier list to find the function */
			for (j = 0; spec_lst[j].specifier != NULL; j++)
			{
				if (format[i + 1] == spec_lst[j].specifier[0])
				{
					temp = spec_lst[j].printer(args);
					if (temp == -1)
						return (-1);
					nb_printedchars = nb_printedchars + temp;
					break;
				}
			}
			if (spec_lst[j].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					nb_printedchars = nb_printedchars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			nb_printedchars++;
		}
	}
	return (nb_printedchars);
}


/**
 * _printf - Custom printf function that
 * handles specifier like %c, %s, and % ...
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int nb_printedchars;

	specifier_handler specifier_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};
	va_list arg_list;
	/* if the format is empty or not exist indicate an error */
	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	/**
	 * Calling convertX function to convert formate to the correct
	 * specifer and calls the appropriate table member
	 */
	nb_printedchars = convertX(format, specifier_list, arg_list);
	va_end(arg_list);

	return (nb_printedchars);
}
