#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * op_add - add two ints
 * @a: int a
 * @b: int b
 *
 * Return: a + b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtract two ints
 * @a: int a
 * @b: int b
 *
 * Return: a - b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply two ints
 * @a: int a
 * @b: int b
 *
 * Return: a * b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divide two ints
 * @a: int a
 * @b: int b
 *
 * Return: a / b, exits with status 100 if b = 0
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - int modulo int
 * @a: int a
 * @b: int b
 *
 * Return: a % b, exit with status 100 if b = 0
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
