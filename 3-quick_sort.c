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
	size_t pivot = size - 1;
	size_t index, swap;
	int do_swap;

	if (!array || size < 2)
		return;

	while (pivot > 0)
	{
		for (index = 0; index < pivot && array[index] < array[pivot]; index++)
			;

		if (index < pivot)
		{
			for (swap = index + 1; swap <= pivot; swap++)
			{
				if (swap != pivot && array[swap] < array[pivot])
				{
					do_swap = array[index];
					array[index] = array[swap];
					array[swap] = do_swap;
					break;
				}
				else if (swap == pivot)
				{
					do_swap = array[index];
					array[index] = array[pivot];
					array[pivot] = do_swap;
				}
			}
			print_array(array, size);
		}
		else
			--pivot;
	}
}
