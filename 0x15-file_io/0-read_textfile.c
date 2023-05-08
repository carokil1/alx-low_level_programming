#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads a text file and prints it to STDOUT.
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t wr;
	ssize_t r;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	r = read(fd, buf, letters);
	wr = write(STDOUT_FILENO, buf, r);

	free(buf);
	close(fd);
	return (wr);
}

