#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * length_list - Calculate the length of the node
 *
 * @list: The list we search the len
 * Return: Length
 */
int length_list(listint_t **list)
{
	listint_t *current = *list;
	int len = 0;

	while (current)
	{
		current = current->next;
		len++;
	}

	return (len);
}

/**
 * swap_cocktail - Do the swap for the cocktail
 *
 * @list: List need to be sort
 * @swapNode: the current node
 */
void swap_cocktail(listint_t **list, listint_t *swapNode)
{
	if (!swapNode->prev)
		*list = swapNode->next;
	else
		swapNode->prev->next = swapNode->next;

	swapNode->next->prev = swapNode->prev;
	swapNode->prev = swapNode->next;
	swapNode->next = swapNode->next->next;
	swapNode->prev->next = swapNode;
	if (swapNode->next)
		swapNode->next->prev = swapNode;
}

/**
 * cocktail_sort_list - The algorithm of the cocktail sort in C
 *
 * @list: The list need to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *swapnode = NULL;
	bool is_swap = true;
	int len_list, loop = 0, min = 0;

	if (!list || !*list || !(*list)->next)
		return;
	swapnode = *list;
	len_list = (length_list(list) - 1);
	while (is_swap)
	{
		is_swap = false;
		for (; loop < len_list; loop++)
		{
			if (swapnode->n > swapnode->next->n)
			{

				swap_cocktail(list, swapnode);
				print_list(*list);
				is_swap = true;
			}
			else
				swapnode = swapnode->next;
		}
		if (!is_swap)
			break;
		is_swap = false;
		for (; loop > min; loop--)
		{
			if (swapnode->n < swapnode->prev->n)
			{
				swap_cocktail(list, swapnode->prev);
				print_list(*list);
				is_swap = true;
			}
			else
				swapnode = swapnode->prev;
		}
		len_list -= 1;
		min += 1;
	}
}
