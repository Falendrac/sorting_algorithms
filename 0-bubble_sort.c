#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * bubble_sort - Sort an array with the bubble sort algorithm
 *
 * @array: Array of int, that need be sort
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index = 0;
	int swap = 0;
	int is_swap;

	if (!array || size < 2)
		return;
	while (1)
	{
		if (index == 0)
			is_swap = false;
		if (index < size - 1 && array[index] > array[index + 1])
		{
			swap = array[index];
			array[index] = array[index + 1];
			array[index + 1] = swap;
			is_swap = true;
			index++;
			print_array(array, size);
		}
		else if (index < size - 1)
			index++;
		else if ((index >= size - 1) && !is_swap)
			break;
		else if (index >= size - 1)
			index = 0;
	}
}
