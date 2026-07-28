#include "variadic_functions.h"

/**
 * print_numbers - print a list of numbers with specified seperator
 * @sep: seperator
 * @n: number of variable inputs
 *
 * Return: 0 always
 */
int print_numbers(const char *sep, const unsigned int n, ...)
{
	va_list args;
	int i = 0;
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf("%s", sep);

		printf("%d", va_arg(args, int));
	}
	printf("\n");
	va_end(args);

	return (0);
}
