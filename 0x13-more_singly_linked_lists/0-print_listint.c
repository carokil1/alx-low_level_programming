#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints elements of the linked list
 *
 * @h: head of the linked list node
 *
 * Return: the number of nodes
 *
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != 0)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
return (count);
}
