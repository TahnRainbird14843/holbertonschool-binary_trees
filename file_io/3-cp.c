#include "main.h"

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
	int close_from;
	int close_to;
	ssize_t in;
	ssize_t out;
	int len = 1024;
	char *buffer = malloc(1024);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);

	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Can't write to %s\n", argv[2]);
		exit(98);
	}

	do {
		in = read(file_from, buffer, 1024);
		len = strlen(buffer);
		out = write(file_to, buffer, len);
		memset(buffer, 0, len);
		if (in == -1)
		{
			dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]);
			exit(98);
		}
		if (out == -1)
		{
			dprintf(STDERR_FILENO, "Can't write to %s\n", argv[2]);
			exit(99);
		}
	} while (len != 0);

	free(buffer);
	close_from = close(file_from);
	close_to = close(file_to);

	if (close_from == -1)
	{
		dprintf(STDERR_FILENO, "Can't close fd %d\n", file_from);
		exit(100);
	}
	if (close_to == -1)
	{
		dprintf(STDERR_FILENO, "Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
