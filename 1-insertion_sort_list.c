#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * insertion_swap - The swap function for insertion algorithm
 *
 * @list: The original list
 * @current: the node we swap with is next
 */
void insertion_swap(listint_t **list, listint_t *current)
{
	listint_t *swap;

	swap = current;
	current = current->next;
	if (swap == *list)
		*list = current;
	else
		swap->prev->next = current;
	if (current->next)
		current->next->prev = swap;
	current->prev = swap->prev;
	swap->prev = current;
	swap->next = current->next;
	current->next = swap;
}

/**
 * insertion_sort_list - Sort a linked list of type listint_t
 *
 * @list: The list we need to sort
 */
void insertion_sort_list(listint_t **list)
{
	bool is_swap;
	listint_t *current = *list;

	if (!list || !*list)
		return;

	while (1)
	{
		if (current == *list)
			is_swap = false;

		if (current->next && current->n > current->next->n)
		{
			insertion_swap(list, current);
			is_swap = true;
			print_list(*list);
		}
		else if (is_swap)
			current = *list;
		else if (current->next)
			current = current->next;
		else
			break;
	}
}
