#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a listint_t list
 * @head: pointer to the first node in the list
 * @n: integer to insert in the new node
 *
 * Return: pointer to the new node, otherwise NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *curr = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (curr->next)
		curr = curr->next;

	curr->next = new;

	return (new);
}

