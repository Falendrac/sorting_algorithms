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
	listint_t *currentNext;

	currentNext = current->next;

	if (!current->prev)
		*list = currentNext;
	else
		current->prev->next = currentNext;

	if (currentNext->next)
		currentNext->next->prev = current;

	currentNext->prev = current->prev;
	current->prev = currentNext;
	current->next = currentNext->next;
	currentNext->next = current;
}

/**
 * insertion_sort_list - Sort a linked list of type listint_t
 *
 * @list: The list we need to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (!list || *list == NULL)
		return;

	current = *list;

	while (current)
	{
		if (current->next && current->n > current->next->n)
		{
			insertion_swap(list, current);
			print_list(*list);
			current = *list;
		}
		else
			current = current->next;
	}
}
