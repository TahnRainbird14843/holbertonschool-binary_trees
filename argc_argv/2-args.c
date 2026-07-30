#include <stdio.h>

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg list
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}
