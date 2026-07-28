#include "variadic_functions.h"

/**
 * print_strings - print a variable list of strings with given seperator
 * @sep: seperator
 * @n: number of strings to print
 *
 * Return: 0 always
 */
int print_strings(const char *sep, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf("%s", sep);

		printf("%s", va_arg(args, char *));
	}
	printf("\n");
	va_end(args);

	return (0);
}
