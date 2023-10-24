#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

/**
 * free_listint2 - Prints the elements of a linked list of integers.
 *
 * @head: A pointer to the head of the linked list.
 *
 * Description: The function sets the head to NULL
 *
 * Return: Void.
 */

void free_listint2(listint_t **head)
{
	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
