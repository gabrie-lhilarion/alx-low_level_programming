#include "lists.h"

/**
 * _strlen - Returns the length of a string of characters.
 * @str: A pointer to a string of characters
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
 * add_node - Add a new node to the beginning of a linked list.
 * @head: A pointer to a pointer to the head of the list
 * @str: The string to be stored in the new node
 * Return: A pointer to the newly added node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = _strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
