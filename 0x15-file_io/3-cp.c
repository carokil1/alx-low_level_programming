#include "main.h"
#include <stdlib.h>
#include <stdio.h>


#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	int fd_from = open(argv[1], O_RDONLY);

	if (argc != 3 || fd_from == -1)
	{
		dprintf(STDERR_FILENO, argc != 3 ?
				"Usage: cp file_from file_to\n" :
				"Error: Can't read from file %s\n", argv[1]);
		exit(argc != 3 ? 97 : 98);
	}

	int fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	char buffer[BUFFER_SIZE];
	ssize_t num_read, num_written;

	while ((num_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		num_written = write(fd_to, buffer, num_read);
		if (num_written == -1 || num_written != num_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (num_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
