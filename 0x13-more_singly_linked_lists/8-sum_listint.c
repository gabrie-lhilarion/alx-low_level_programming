#include <stdio.h>
#include <stdlib.h>

#include "lists.h"


/**
 * sum_listint - Function sums the values in a liked list.
 *
 * @head: A pointer to the pointer to the head of the linked list.
 *
 * Description: This function sums the values of the list
 *
 * Return:  Some on node values
 */

int sum_listint(listint_t *head)
{
	listint_t *start = head;

	int sum = 0;

	if (start == NULL)
		return (0);

	while (start != NULL)
	{
		sum += start->n;
		start = start->next;
	}

	return (sum);
}
