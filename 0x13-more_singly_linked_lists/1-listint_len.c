#include <stdio.h>
#include "lists.h"

/**
 * listint_len - Prints the elements of a linked list of integers.
 *
 * @h: A pointer to the head of the linked list.
 *
 * This function counts the number of elements in the list.
 *
 * Return: The number of elements in the linked list.
 */

size_t listint_len(const listint_t *h)
{
	size_t num_elements = 0;

	while (h != NULL)
	{
		h = h->next;

		num_elements++;
	}

	return (num_elements);
}
