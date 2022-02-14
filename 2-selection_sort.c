#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - The selection algorithm in C with 2/3 loops
 *
 * @array: The array we need to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t loopSort, searchMini, index;
	int swap, mini;

	for (loopSort = 0; loopSort < size - 1; loopSort++)
	{
		index = loopSort;
		mini = array[loopSort];

		for (searchMini = loopSort + 1; searchMini < size; searchMini++)
		{
			if (mini > array[searchMini])
			{
				index = searchMini;
				mini = array[searchMini];
			}
		}

		if (index != loopSort)
		{
			for (searchMini = loopSort; searchMini < index; searchMini++)
			{
				swap = array[searchMini + 1];
				array[searchMini + 1] = array[searchMini];
				array[searchMini] = mini;

				mini = swap;
			}
			print_array(array, size);
		}
	}
}
