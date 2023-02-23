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

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			printf("%2d%s", i * j, j == 9 ? "\n" : ", ");
		}
	}
}
