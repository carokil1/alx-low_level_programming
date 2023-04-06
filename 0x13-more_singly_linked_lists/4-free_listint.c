#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees a linked list
 * @head: pointer to the head node of the list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *curr, *next;

	curr = head;

	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}
