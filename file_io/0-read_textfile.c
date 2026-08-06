#include "main.h"

/**
 * read_textfile - read a text file and print to stdout
 * @filename: filename to read
 * @letters: number of chars to print
 *
 * Return: number of letters printed, 0 on fail
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	size_t fd;
	ssize_t out;
	char *buffer = malloc(letters);

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	out = read(fd, buffer, letters);

	if (out < 0)
		return (0);

	write(STDOUT_FILENO, buffer, letters);

	close(fd);

	return (out);
}
