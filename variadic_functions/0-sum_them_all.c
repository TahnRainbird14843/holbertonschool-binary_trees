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
	int sum;
	unsigned int i;

	va_start(args, n);
	sum = 0;
	i = 0;

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	va_end(args);

	return (sum);
}
