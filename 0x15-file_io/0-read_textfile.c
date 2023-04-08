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
	int fd, num_read, num_written;
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

	num_read = read(fd, buffer, letters);
	close(fd);

	if (num_read == -1)
	{
		free(buffer);
		return (0);
	}

	buffer[num_read] = '\0';

	num_written = write(STDOUT_FILENO, buffer, num_read);
	free(buffer);

	if (num_written == -1 || num_written != num_read)
		return (0);

	return (num_written);
}
