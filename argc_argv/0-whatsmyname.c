#include <stdio.h>

/**
 * main - entry point
 * @argc: count of args
 * @argv: list of char * args
 *
 * Return: 0 always
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *name = argv[0];
	int i = 0;

	while (name[i] != '\0')
		putchar(name[i++]);
	putchar('\n');

	return (0);
}
