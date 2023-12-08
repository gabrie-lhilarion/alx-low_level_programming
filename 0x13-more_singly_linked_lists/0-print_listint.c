#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Prints the elements of a linked list of integers.
 *
 * @h: A pointer to the head of the linked list.
 *
 * This function traverses a linked list of integers, starting from the given
 * head node, and prints each integer element. It counts the number of nodes
 * (elements) in the list and returns that count.
 *
 * Return: The number of nodes (elements) in the linked list.
 */

size_t print_listint(const listint_t *h)
{

	size_t num_nodes = 0;

	while (h != NULL)
	{
		int num = h->n;

		h = h->next;

		printf("%d\n", num);

		num_nodes++;
	}

	return (num_nodes);
}
