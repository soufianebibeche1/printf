#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @printer: the function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*printer)(va_list);
} specifier_handler;

/* writinng and printing functions functions */
int _putchar(char c);
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);

/* format specifiers */
int convertX(const char *format, specifier_handler spec_lst[], va_list args);

/* _printf */
int _printf(const char *format, ...);


#endif
