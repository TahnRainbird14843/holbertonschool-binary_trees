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
 * search_buffer - search a buffer for the last time a character appears
 * @buffer: buffer to search
 *
 * Return: length of string up to last non-null char
 */
int search_buffer(char *buffer)
{
	int i = 0;
	int len = 0;

	while (i < 1024)
	{
		if (buffer[i] != '\0')
			len = i + 1;
		i++;
	}

	return (len);
}

/**
 * _memset - implementation of memset
 * @buffer: pointer to memory
 * @value: value to be reset to
 * @num: number of bytes to overwrite
 *
 * Return: 0 always.
 */
int _memset(char *buffer, char value, int num)
{
	int i = 0;

	while (i < num)
	{
		buffer[i] = value;
		i++;
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
	int len = 1024;
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
		len = search_buffer(buffer);
		out = write(file_to, buffer, len);
		_memset(buffer, '\0', 1024);
		if (in == -1)
			throw_error(1, argv[1], 0);
		if (out == -1)
			throw_error(2, argv[2], 0);
	} while (len != 0);

	free(buffer);

	if (close(file_from) == -1)
		throw_error(3, NULL, file_from);
	if (close(file_to) == -1)
		throw_error(3, NULL, file_to);

	return (0);
}
