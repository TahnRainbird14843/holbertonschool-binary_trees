#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - return a pointer to functions corresponding to an operator
 * @s: operator character
 *
 * Return: pointer to the correct function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	while (ops[i].op != NULL)
	{
		if (*(ops[i].op) == *s && s[1] == '\0')
			return (ops[i].f);

		i++;
	}

	return (NULL);
}
