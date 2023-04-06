#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - the sum of all the data (n) in a listint_t list.
 * @head: pointer to the head node of the list
 *
 * Return: sum of all the data in the list
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *curr;

	if (head == NULL)
		return (0);

	curr = head;
	while (curr != NULL)
	{
		sum += curr->n;
		curr = curr->next;
	}

	return (sum);
}
