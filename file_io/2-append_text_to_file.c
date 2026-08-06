#include "main.h"

/**
 * append_text_to_file - append text to a file
 * @filename: filename
 * @text_content: text to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t wr_out;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd < 0)
		return (-1);

	if (text_content == NULL)
		wr_out = write(fd, "", 0);
	else
		wr_out = write(fd, text_content, strlen(text_content) + 1);

	if (wr_out < 0)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
