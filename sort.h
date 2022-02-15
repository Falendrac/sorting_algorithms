#ifndef SORT_H
#define SORT_H

/* All includes needed for the project */
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Functions given by Holberton */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Functions made us */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Advanced functions */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

/* Function for insertion sort */
void insertion_swap(listint_t **list, listint_t *current);

/* Function for quick sort */
void swap(int *array, size_t size, ssize_t i, ssize_t j);
size_t lomuto(int *array, size_t size, ssize_t lower, ssize_t high);
void my_quicksort(int *array, size_t size, ssize_t lower, ssize_t high);

/* Function for cocktail sort */
void swap_cocktail(listint_t **list, listint_t *swapNode);
int length_list(listint_t **list);

#endif
