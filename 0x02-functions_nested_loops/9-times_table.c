#include <stdio.h>
#include "main.h"
/**
 * times_table - prints multiplication table
 *
 *
 * Return: always 0
 */

void times_table(void)
{
	int i, j;

	printf("  0  1  2  3  4  5  6  7  8  9\n");
	printf("------------------------------\n");
	for (i = 0; i <= 9; i++)
	{
		printf("%2d|", i);
		for (j = 0; j <= 9; j++)
		{
			printf("%2d ", i * j);
		}
		printf("\n");
	}
}
