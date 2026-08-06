#include "main.h"

/**
 * throw_error - handles error output
 * @n: int input
 * @name: name associated with error
 * @num: num associated with error
 *
 * Return: 0 always
 */
int throw_error(int n, char *name, int num)
{
	if (n == 0)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (n == 1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name);
		exit(98);
	}
	if (n == 2)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
		exit(99);
	}
	if (n == 3)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", num);
		exit(100);
	}

	return (0);
}

/**
 * main - entry point, copies a file (same as cp in terminal)
 * @argc: arg count
 * @argv: list of args
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int file_from;
	int file_to;
	ssize_t in;
	ssize_t out;
	char *buffer = malloc(1024);

	if (argc != 3)
		throw_error(0, NULL, 0);

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);

	if (file_from == -1)
		throw_error(1, argv[1], 0);
	if (file_to == -1)
		throw_error(2, argv[2], 0);

	do {
		in = read(file_from, buffer, 1024);
		out = write(file_to, buffer, in);
		if (in == -1)
			throw_error(1, argv[1], 0);
		if (out == -1)
			throw_error(2, argv[2], 0);
	} while (in == 1024);

	free(buffer);

	if (close(file_from) == -1)
		throw_error(3, NULL, file_from);
	if (close(file_to) == -1)
		throw_error(3, NULL, file_to);

	return (0);
}
