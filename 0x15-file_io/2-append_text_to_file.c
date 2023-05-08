#include "main.h"

/**
 * * append_text_to_file - appends text to the end of a file
 * @filename: the name of the file to append to
 * @text_content: a NULL-terminated string to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	wr = write(fd, text_content, length);

	if (fd == -1 || wr == -1)
		return (-1);

	close(fd);

	return (1);
}

