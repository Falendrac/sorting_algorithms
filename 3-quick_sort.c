#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - The quick sort algorithm in C
 *
 * @array: The array we want to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	my_quicksort(array, size, 0, size - 1);
}

/**
 * my_quicksort - Using quicksort in recursivity
 *
 * @array: The array we want to sort
 * @size: The size of the array
 * @lower: the lower index of array
 * @high: the highest index of array
 */
void my_quicksort(int *array, size_t size, ssize_t lower, ssize_t high)
{
	int parti;

	if (lower < high)
	{
		parti = lomuto(array, size, lower, high);
		my_quicksort(array, size, lower, parti - 1);
		my_quicksort(array, size, parti + 1, high);
	}
}

/**
 * lomuto - Lomuto method for quick sort
 *
 * @array: The array we want to sort
 * @size: The size of the array
 * @lower: the lower index of array
 * @high: the highest index of array
 * Return: The current index sorting
 */
size_t lomuto(int *array, size_t size, ssize_t lower, ssize_t high)
{
	int pivot = array[high];
	ssize_t i = lower;
	ssize_t j;

	for (j = lower; j < high; j++)
	{
		if (pivot > array[j])
		{
			if (i != j)
			{
				swap(array, size, i, j);
			}
			i++;
		}
	}
	if (array[high] < array[i])
		swap(array, size, i, high);

	return (i);
}

/**
 * swap - Swap the two values in index i and j
 *
 * @array: The array we want to sort
 * @size: The size of the array
 * @i: First elements to swap
 * @j: Second elements to swap
 */
void swap(int *array, size_t size, ssize_t i, ssize_t j)
{
	int do_swap;

	do_swap = array[i];
	array[i] = array[j];
	array[j] = do_swap;

	print_array(array, size);
}
