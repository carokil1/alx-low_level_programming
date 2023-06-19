#include "main.h"

/**
 * _abs - function that checks for absolute value
 * @a: function parameter to be checked
 *
 * Return: always a
 */

int _abs(int a)
{
	if (a < 0)
		a = -(a);
	else if (a >= 0)
		a = a;
	return (a);
}
