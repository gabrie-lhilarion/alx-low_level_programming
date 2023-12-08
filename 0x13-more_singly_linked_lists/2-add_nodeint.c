#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Prints the elements of a linked list of integers.
 *
 * @head: A pointer to the head of the linked list.
 *
 * @n: Integer which is the data oe value of the new node
 *
 * Return: The number of elements in the linked list.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *created_node = malloc(sizeof(listint_t));

	if (created_node == NULL)
	{
		return (NULL);
	}

	created_node->n = n;

	created_node->next = *head;

	*head = created_node;

	return (created_node);
}
