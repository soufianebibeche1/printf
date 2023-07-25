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
 * print_number - prints an integer argument
 * @args: the argument to print
 * Return: number of characters printed
 */
int print_number(va_list args)
{
	int n, divisor, len;
	unsigned int num;

	n  = va_arg(args, int);
	divisor = 1;
	len = 0;

	if (n < 0)
	{
		len = len * _putchar('-');
		num = n * -1;
	}
	else
	{
		num = n;
	}

	while (num / divisor > 9)
	{
		divisor = divisor * 10;
	}

	while (divisor != 0)
	{
		len = len + _putchar('0' + num / divisor);
		num = num % divisor;
		divisor = divisor / 10;
	}

	return (len);
}

/**
 * print_int - Prints the percent symbol
 * @args: list of arguments
 * Return: 1 for succes of printing.
 */
int print_int(va_list args)
{
	int nb_printedchars;

	nb_printedchars = print_number(args);
	return (nb_printedchars);
}
