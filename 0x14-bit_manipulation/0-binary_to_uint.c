#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts binary numbers to unsigned integers
 * @b: Pointer to the binary number strings
 *
 * Return: converted number or if b is NULL
 */

unsigned int binary_to_uint(const char *b)

{
	int a;
	unsigned int ans = 0;

	if (!b)
		return (0);

	for (a = 0; b[a]; a++)
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		ans = 2 * ans + (b[a] - '0');
	}

	return (ans);
}

