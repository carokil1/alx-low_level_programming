#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes a node at a given index in a linked list
 * @head: Pointer to the head of the linked list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node = *head;
	listint_t *current_node = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(prev_node);
		return (1);
	}

	while (i < index - 1)
	{
		if (!prev_node || !(prev_node->next))
			return (-1);
		prev_node = prev_node->next;
		i++;
	}

	current_node = prev_node->next;
	prev_node->next = current_node->next;
	free(current_node);

	return (1);
}
