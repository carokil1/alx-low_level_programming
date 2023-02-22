#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - function that prints natural numbers
 *
 * @n: function parameter
 * Return: always 0
 */

void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i < 98; i++)
		{
			printf("%d, ", i);
		}
	}
	else
	{
		for (i = n; i > 98; i--) 
	{
		printf("%d, ", i);
        }
	}
	printf("98\n");
}

