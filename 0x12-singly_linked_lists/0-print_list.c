#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all elements in a linked list
 * @h: the pointer to the list to print
 *
 * Return: the number of nodes printed
 *
 *
 */

size_t print_list(const list_t *h)
{
	size_t printed = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		h = h->next;
		printed++;
	}

	return (printed);

}
