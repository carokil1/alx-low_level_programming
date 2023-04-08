#include "main.h"

/**
 * flip_bits - returns the number of bits needed to flip to get from n to m
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_diff = n ^ m;
	unsigned int count = 0;

	while (bit_diff > 0)
	{
		count += bit_diff & 1;
		bit_diff >>= 1;
	}

	return (count);
}
