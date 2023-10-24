#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

/**
 * pop_listint - Remove the head and return the data.
 *
 * @head: A pointer to the pointer to the head of the linked list.
 *
 * Description: Removes the head and returns the vale
 *
 * Return: Return Int, the value of the in
 */

int pop_listint(listint_t **head)
{

	listint_t *this_head = *head;
	int data;

	if (*head == NULL)
	{
		return (0);
	}

	data = this_head->n;

	*head = this_head->next;

	free(this_head);

	return (data);
}
