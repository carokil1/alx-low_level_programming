
#include "main.h"

/**
 * * get_bit - returns the value of a bit at a given index
 * @n: the number to examine
 * @index: the index of the bit to retrieve
 * Return: bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}

