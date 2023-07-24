#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - print character
 * @c: a character to print
 * Return: the number of bytes that were successfully written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - print an argument character
 * @args: the argument to print
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - print a string argument
 * @args: the argument to print
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_percent - Prints the percent symbol
 * @list: list of arguments
 * Return: 1 for succes of printing.
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_int - prints an integer argument
 * @args: the argument to print
 * Return: number of characters printed
 */

