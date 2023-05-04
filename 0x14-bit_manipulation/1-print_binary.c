#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int a, printed = 0;
	unsigned long int curr;

	for (a = 63; a >= 0; a--)
	{
		curr = n >> i;

		if (curr & 1)
		{
			_putchar('1');
			printed++;
		}
		else if (printed)
			_putchar('0');
	}
	if (!printed)
		_putchar('0');
}

