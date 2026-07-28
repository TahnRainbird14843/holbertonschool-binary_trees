#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>

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
	char *pr_ch;
	char *type;
} typ_t;

int sum_them_all(const unsigned int n, ...);
int print_numbers(const char *sep, const unsigned int n, ...);
int print_strings(const char *sep, const unsigned int n, ...);
int print_all(const char *format, ...);

#endif
