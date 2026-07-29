#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct typ - type structure includes character, identifier for printf and type
 * 
 * @ch: corresponding character (cifs)
 * @pr_ch: printf identifier (%d, %f, %c, %s)
 * @type: string for type
 */
typedef struct typ
{
	char ch;
	int (*f)(char *s);
} typ_t;

int sum_them_all(const unsigned int n, ...);
int print_numbers(const char *sep, const unsigned int n, ...);
int print_strings(const char *sep, const unsigned int n, ...);
int print_all(const char *format, ...);
int print_char(char *s);
int print_int(char *s);
int print_float(char *s);
int print_string(char *s);
int (*get_print_func(char c))(char *);

#endif
