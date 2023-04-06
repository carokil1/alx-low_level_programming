#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to the head of the listint_t list.
 * @n: The integer to be stored in the new node.
 *
 * Return: If successful - a pointer to the new node. Otherwise - NULL.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *curr;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		curr = *head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}

	return (new);
}
