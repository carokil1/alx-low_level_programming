#include <stdio.h>
#include "main.h"
/**
 * jack_bauer - prints time in 24hrs
 *
 * Return: always 0
 */

void jack_bauer(void)

{
	int hour;
	int minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
			printf("%02d:%02d\n", hour, minute);
		}
	}
}
