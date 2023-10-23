#include <stdio.h>
#include "lists.h"

size_t print_listint(const listint_t *h)
{

    size_t num_nodes = 0;
    while (h != NULL)
    {
        /* code */
        int num = h->n;
        h = h->next;

        prinf("%d", num);
        num_nodes++;
    }

    return (num_nodes);
}
