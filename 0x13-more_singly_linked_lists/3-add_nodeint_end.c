#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

/**
 * add_nodeint_end - Prints the elements of a linked list of integers.
 *
 * @head: A pointer to the head of the linked list.
 *
 * @n: Integer which is the data oe value of the new node
 *
 * Return: The new node or null.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *created_node = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (created_node == NULL)
		return (NULL);

	created_node->n = n;
	created_node->next = NULL;

	if (*head == NULL)
	{
		*head = created_node;

		return (created_node);
	}

	while (current->next != NULL)
		current = current->next;

	current->next = created_node;

	return (created_node);
}
