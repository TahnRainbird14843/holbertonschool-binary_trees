#include "variadic_functions.h"

/**
 * print_char - print a character given as a string
 * @s: input string (one character)
 *
 * Return: 0 always
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	printf("%c", c);

	return (0);
}

/**
 * print_int - print an int given as a string
 * @s: in put string
 *
 * Return: 0 always
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);

	printf("%d", n);
	
	return (0);
}

/**
 * print_float - print a float given as a string
 * @s: input string
 *
 * Return: 0 always
 */
int print_float(va_list args)
{
	float f = va_arg(args, double);

	printf("%f", f);

	return (0);
}

/**
 * print_string - print a string
 * @s: input string
 *
 * Return: 0 always
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return (0);
	}

	printf("%s", s);

	return (0);
}

/**
 * print_all - print a list of elements of variable types
 * @format: list of types of variables
 *
 * Return: 0 always
 */
int print_all(const char *format, ...)
{
	int i = 0;
	va_list args;
	char *sep = "";
	int j = 0;
	typ_t types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string}
	};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;

		while (j < 4)
		{
			if (format[i] == types[j].ch)
			{
				printf("%s", sep);
				types[j].f(args);
			}

			j++;
		}

		sep = ", ";
		i++;
	}

	printf("\n");
	va_end(args);

	return (0);
}
