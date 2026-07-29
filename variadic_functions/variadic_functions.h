#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct typ - type structure includes character,
 * identifier for printf and type
 *
 * @ch: corresponding character (cifs)
 * @f: correpsonding function
 */
typedef struct typ
{
	char ch;
	int (*f)(va_list);
} typ_t;

int sum_them_all(const unsigned int n, ...);
int print_numbers(const char *sep, const unsigned int n, ...);
int print_strings(const char *sep, const unsigned int n, ...);
int print_all(const char *format, ...);
int print_char(va_list args);
int print_int(va_list args);
int print_float(va_list args);
int print_string(va_list args);
int (*get_print_func(char c))(va_list);

#endif
