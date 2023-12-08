#include <stdio.h>
#include <stdlib.h>

struct List
{
    int item;
    struct List *next;
};

/* Add new item to the next position in the list after node. */
struct List *insert_after(struct List *node, int item)
{
    /* Allocate memory for new node. */
    struct List *newnode = (struct List *)malloc(sizeof(struct List));

    if (newnode == NULL)
        return NULL; /* allocation failed */

    /* If list is not empty, splice new node into list. */
    if (node)
    {
        newnode->next = node->next;
        node->next = newnode;
    }
    else
    {
        newnode->next = NULL;
    }

    newnode->item = item;
    return newnode;
}