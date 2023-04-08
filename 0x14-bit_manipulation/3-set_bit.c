#include "main.h"

/**
 * set_bit - returns the value of a bit at a given index
 * @n: pointer to the number to get the bit from
 * @index: the index of the bit to set starts fro 0
 *
 * Return: 1 ifsuccessful or -1 if error occurs
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);

	*n = (*n | (1 << index));

	return (1);
}

