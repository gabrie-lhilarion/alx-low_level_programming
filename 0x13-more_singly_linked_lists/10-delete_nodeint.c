#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node on linked list at index
 * @head: pointer to first element on list
 * @index: index of the node to br deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp = *head;
    listint_t *current_node = NULL;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = (*head)->next;

        free(temp);

        return (1);
    }

    while (i < index - 1)
    {
        if (!temp || !(temp->next))
            return (-1);

        temp = temp->next;
        i++;
    }

    current_node = temp->next;
    temp->next = current_node->next;
    free(current_node);

    return (1);
}
