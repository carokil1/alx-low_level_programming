#include "main.h"
#include <unistd.h>

/**
 * _putchar -  writes a character to the standard output stream
 * @c: the character to write
 *
 * Return: 1 On success
 * -1 is returned On error, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
i
