#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

/**
 * free_listint - Prints the elements of a linked list of integers.
 *
 * @head: A pointer to the head of the linked list.
 *
 * Description: The function sets the head to NULL
 *
 * Return: Void.
 */

void free_listint(listint_t *head)
{
	while (head != NULL)
	{
		listint_t *tmp = head;

		head = head->next;

		free(tmp);
	}
}
