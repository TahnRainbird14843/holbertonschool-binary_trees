#include "variadic_functions.h"

/**
 * sum_them_all - sum a variable set of integers
 * @n: number of integers to be summed
 *
 * Return: sum of rest of integers
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	va_start(args, n);
	int sum = 0;
	unsigned int i = 0;

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	va_end(args);

	return(sum);
}
