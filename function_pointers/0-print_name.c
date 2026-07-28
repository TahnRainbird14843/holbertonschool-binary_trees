#include "function_pointers.h"

/**
 * print_name - print a name using a function pointer
 * @s: name to print
 * @f: function to print name
 *
 * Return: 0 always
 */
int print_name(char *s, void (*f)(char *))
{
	f(s);

	return (0);
}
