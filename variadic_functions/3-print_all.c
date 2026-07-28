#include "variadic_functions.h"

/**
 * print_all - print a list of elements of variable types
 * @format: list of types of variables
 *
 * Return: 0 always
 */
int print_all(const char *format, ...)
{
	va_list args;
	int i = 0;
	typ_t typ[4] = {
		{'c', "%c", "char"},
		{'i', "%d", "int"},
		{'f', "%f", "float"},
		{'s', "%s", "char *"}
	};
	int j = 0;
	va_start(args, strlen(format));

	while (format[i] != '\0')
	{
		if (i != 0)
			printf(", ");

		while (j < 4)
		{
			if (format[i] == typ[j].ch)
			{
				printf(typ[j].pr_ch, va_arg(args, typ[j].type));
				break;
			}
			else
				j++;
		}

		i++;
	}
	printf("\n");
	va_end(args);

	return (0);
}
