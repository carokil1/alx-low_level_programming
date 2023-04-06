#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the first node of the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the nth node of list
 *
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a;
	listint_t *current_node;

	current_node = head;

	for (a = 0; current_node != NULL && a < index; a++)
	{
		current_node = current_node->next;
	}

	if (a == index && current_node != NULL)
	{
		return (current_node);
	}

	return (NULL);
}
