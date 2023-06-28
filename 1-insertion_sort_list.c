#include "sort.h"

void swap_nodes(listint_t *a, listint_t *b);

/**
 * insertion_sort_list - sorting a dll using insertion sort algorithm
 * @list: double pointer to a dll
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *unsorted;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		unsorted = current;
		current = current->next;

		while (unsorted->prev != NULL && unsorted->prev->n > unsorted->n)
		{
			if (*list == unsorted->prev)
				*list = unsorted;
			swap_nodes(unsorted->prev, unsorted);
			print_list(*list);
		}
	}
}

/**
 * swap_nodes - swapping two nodes in dll
 * @a: pointer to first node to swap
 * @b: pointer to second node to swap
*/
void swap_nodes(listint_t *a, listint_t *b)
{
	a->next = b->next;

	if (b->next != NULL)
		b->next->prev = a;
	if (a->prev != NULL)
		a->prev->next = b;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
