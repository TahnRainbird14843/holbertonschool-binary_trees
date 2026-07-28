#include "variadic_functions.h"

/**
 * keep_types - takes a string a keeps only letters corresponding to desired types
 * @s: input string
 *
 * Return: new string with only desired letters
 */
char *keep_types(char *s)
{
	int i = 0;
	int j = 0;
	char *out;

	while (s[i] != '\0')
	{
		if (s[i] == 'c' || s[i] == 'f' || s[i] == 'i' || s[i] == 's')
		{
			out[j] = s[i];
			i++;
			j++;
		}
		else
			i++;
	}

	return (out);
}

/**
 * print_all - print a list of elements of variable types
 * @format: list of types of variables
 *
 * Return: 0 always
 */
int print_all(const char *format, ...)
{
	va_list args;
	char *types;
	int i = 0;
	int n;
