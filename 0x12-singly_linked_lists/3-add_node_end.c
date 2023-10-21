#include "lists.h"

/**
 * _strlen - Returns the length of a string.
 * @str: A pointer to a string  characters
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	unsigned int len;

	for (len = 0; str[len] != '\0'; len++)
	{
	}
	return (len);

}

/**
 * add_node_end - Add a new node to the end of a linked list.
 * @head: A pointer to a pointer to the head of the list
 * @str: The string to be stored in the new node
 * Return: A pointer to the newly added node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *tmp;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = _strlen(str);
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		{
			tmp->next = new_node;
		}
	}
	return (new_node);
}
