#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>


/*a structure that handle each specifier to the correct function */
typedef struct {
    char *specifier;
    int (*printer)(va_list);
} specifier_handler;

/* writinng and printing functions functions */
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(__attribute__((unused))va_list list);
int print_int(va_list args);


/* _printf */
int _printf(const char *format, ...);


#endif
