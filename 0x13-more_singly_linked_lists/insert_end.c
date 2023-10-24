#include <stdio.h>
#include <stdlib.h>

/**
 * insert_back - Adds a new node at the back of the list, returns the new node.
 *
 * @node: A pointer to the node.
 *
 * @item: Integer to be inserted.
 *
 * This function counts the number of elements in the list.
 *
 * Return: The new node
 */

struct List
{
	int item;
	struct List *next;
};

struct List *insert_end(struct List *node, int item)
{
	/* Allocate memory for new node. */
	struct List *newnode = (struct List *)malloc(sizeof(struct List));

	if (newnode == NULL)
		return (NULL); /* allocation failed */

	newnode->item = item;
	newnode->next = NULL;

	/* If list is not empty, find end of list and attach new node. */

	if (node)
	{
		while (node->next)
			node = node->next;

		node->next = newnode;
	}

	return (newnode);
}
