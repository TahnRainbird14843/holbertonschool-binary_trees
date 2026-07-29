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
	unsigned int i;

	va_start(args, n);
	i = 0;

	for (i = 0; i < n; i++)
	{
		if (i != 0 && sep != NULL)
			printf("%s", sep);

		printf("%d", va_arg(args, int));
	}
	printf("\n");
	va_end(args);

	return (0);
}
