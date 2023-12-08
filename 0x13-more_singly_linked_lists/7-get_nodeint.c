#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

/**
 * get_nodeint_at_index - Functionget the node at a given index.
 *
 * @head: A pointer to the pointer to the head of the linked list.
 * @index: unsigned integer int.
 *
 * Description: This function return the node at a given inex or null
 *
 * Return:  that returns the nth node or null
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current_head = head;

	unsigned int find_index = 0;

	while (current_head != NULL)
	{
		if (find_index == index)
			return (current_head);

		current_head = current_head->next;

		find_index++;
	}

	return (NULL);
}
