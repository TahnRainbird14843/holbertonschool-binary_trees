#include "variadic_functions.h"

/**
 * print_char - print a character given as a string
 * @s: input string (one character)
 *
 * Return: 0 always
 */
int print_char(char *s)
{
	printf("%s", s);

	return (0);
}

/**
 * print_int - print an int given as a string
 * @s: in put string
 *
 * Return: 0 always
 */
int print_int(char *s)
{
	int n = atoi(s);

	printf("%d", n);
	
	return (0);
}

/**
 * print_float - print a float given as a string
 * @s: input string
 *
 * Return: 0 always
 */
int print_float(char *s)
{
	float f = atof(s);

	printf("%f", f);

	return (0);
}

/**
 * print_string - print a string
 * @s: input string
 *
 * Return: 0 always
 */
int print_string(char *s)
{
	if (s == NULL)
	{
		printf("(nil)");
		return (0);
	}

	printf("%s", s);

	return (0);
}

/**
 * get_print_func - find print function for character input
 * @c: character input
 *
 * Return: print function, NULL on fail
 */
int (*get_print_func(char c))(char *)
{
	typ_t types[5] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};
	int i = 0;

	while (types[i].ch != '\0')
	{
		if (c = types[i].ch)
		{
			return (types[i].f);
			break;
		}

		i++;
	}

	return (NULL);
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
	int (*print_func)(char *);

	va_start(args, format);

	if (format == NULL)
		return (0);

	while (format[i] != '\0')
	{
		print_func = get_print_func(format[i]);

		if (print_func != NULL)
			print_func(va_arg(args, char *));

		i++;
	}

	return (0);
}
