#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @left: Pointer to the left node to be swapped.
 * @right: Pointer to the right node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker Sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		swapped = 0;
		current = *list;

		/* Forward pass */
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
        
		/* Backward pass */
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
	} while (swapped);
}
