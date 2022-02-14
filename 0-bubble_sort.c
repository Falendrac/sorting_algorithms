#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

void bubble_sort(int *array, size_t size)
{
	size_t index = 0;
	int swap = 0;
	int is_swap;

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
