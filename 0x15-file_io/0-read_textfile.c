#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to STD OUT
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: letters it could read and print, or 0 if an error occurred
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, num_r, num_w;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	num_r = read(fd, buffer, letters);
	close(fd);

	if (num_r == -1)
	{
		free(buffer);
		return (0);
	}

	buffer[num_r] = '\0';

	num_w = write(STDOUT_FILENO, buffer, num_r);
	free(buffer);

	if (num_w == -1 || num_w != num_r)
		return (0);

	return (num_w);
}
