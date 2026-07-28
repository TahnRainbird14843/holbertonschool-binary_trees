#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>

int sum_them_all(const unsigned int n, ...);
int print_numbers(const char *sep, const unsigned int n, ...);
int print_strings(const char *sep, const unsigned int n, ...);
int print_all(const char *format, ...);

#endif
