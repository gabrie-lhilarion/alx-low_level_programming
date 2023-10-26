#include <stdlib.h>
#include "lists.h"

/**
 * has_cycle - Checks if a linked list has a cycle.
 * @head: A pointer to the head of the list.
 *
 * Return: 1 if there is a cycle, 0 otherwise.
 */

int has_cycle(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return (1);
		}
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current = *h;
	listint_t *temp = NULL;

	if (has_cycle(*h))
	{
		while (current != temp)
		{
			size++;
			temp = current;
			current = current->next;
			free(temp);
		}

		*h = NULL;
	}
	else
	{
		while (current != NULL)
		{
			size++;
			temp = current;
			current = current->next;
			free(temp);

		}

		*h = NULL;
	}

	return (size);
}
