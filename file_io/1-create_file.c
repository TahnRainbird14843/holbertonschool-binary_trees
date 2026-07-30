#include "main.h"

/**
 * create_file - create a file with text content
 * @filename: name of file
 * @text_content: content to be added to file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t out;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

	ftruncate(fd, 0);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	out = write(fd, text_content, strlen(text_content) + 1);

	if (out < 0)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
