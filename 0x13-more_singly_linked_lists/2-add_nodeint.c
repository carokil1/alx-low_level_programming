#include "lists.h"
#include <stdlib.h>

/**
* add_nodeint - ADDS new node with value at start of linked list
* @head: pointS to the first node in the list
* @n: Integer value to be inserted in the new node.
*
* Return: pointer to the new node, NULL if it fails
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *pointer;
	
	pointer = malloc(sizeof(listint_t));
	if (pointer == NULL)
		return (NULL);
	
	pointer->n = n;
	pointer->next = *head;
	*head = pointer;
	
	return (pointer);
}
