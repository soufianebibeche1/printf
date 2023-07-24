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
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int temp, i, divisor, nb_numbers = 0;
	int is_negative = 0;


	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	else if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	temp = n;

	while (temp != 0)
	{
		nb_numbers++;
		temp /= 10;
	}

	divisor = 1;

	for (i = 1; i < nb_numbers; i++)
		divisor *= 10;

	if (is_negative == 1)
		_putchar('-');

	while (divisor > 0)
	{
		_putchar((n / divisor) + '0');
		n %= divisor;
		divisor /= 10;
	}

	return (nb_numbers);
}
