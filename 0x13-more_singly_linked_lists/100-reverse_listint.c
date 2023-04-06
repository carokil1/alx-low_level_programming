#include "lists.h"
#include <stdlib.h>

/**
 * reverse_listint - Reverses a linked list.
 * @head: Pointer to a pointer to the first node of the list.
 *
 * Return: Pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *bef = NULL, *nxt = NULL;

	while (*head)
	{
		nxt = (*head)->nxt;
		(*head)->nxt = bef;
		bef = *head;
		*head = nxt;
	}
	*head = bef;

	return (*head);
}
