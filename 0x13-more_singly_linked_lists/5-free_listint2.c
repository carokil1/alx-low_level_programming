#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list
 * @head: pointer to pointer to the first node of the list
 *
 * Description: The function frees each node of the list and sets the
 *              head to NULL.
 */

void free_listint2(listint_t **head)
{
	listint_t *curr;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		curr = *head;
		*head = curr->next;
		free(curr);
	}

	*head = NULL;
}
