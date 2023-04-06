#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list
 *
 * @head: pointer to the head of the linked list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if successful, -1 if it fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *prev;

	unsigned int a;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return (1);
	}

	prev = *head;

	for (a = 0; prev != NULL && a < index - 1; a++)
		prev = prev->next;

	if (prev == NULL || prev->next == NULL)
		return (-1);

	temp = prev->next->next;
	free(prev->next);
	prev->next = temp;

	return (1);
}
