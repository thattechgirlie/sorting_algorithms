#include "sort.h"
/**
 * swap_nodes - swapping nodes in doublelinked list
 * @h: head pointer
 * @n1: point to node1
 * @n2: point to node2
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort - algorithm to sort double linked list
 * @list: pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *s, *d, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (s = (*list)->next; s != NULL; s = tmp)
	{
		tmp = s->next;
		d = s->prev;
		while (d != NULL && s->n < d->n)
		{
			swap_nodes(list, &d, s);
			print_list((const listint_t*)*list);
		}
	}
}
