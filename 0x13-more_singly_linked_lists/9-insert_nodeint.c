#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *for_insert;
	listint_t *start = *head;

	for_insert = malloc(sizeof(listint_t));

	if (!for_insert || !head)
		return (NULL);

	for_insert->n = n;
	for_insert->next = NULL;

	if (idx == 0)
	{
		for_insert->next = *head;
		*head = for_insert;
		return (for_insert);
	}

	for (i = 0; start && i < idx; i++)
	{
		if (i == idx - 1)
		{
			for_insert->next = start->next;
			start->next = for_insert;
			return (for_insert);
		}
		else
		{
			start = start->next;
		}
	}

	return (NULL);
}
