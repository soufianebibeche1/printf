#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>


/* writinng and printing functions functions */
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);


/* _printf */
int _printf(const char *format, ...);


#endif
