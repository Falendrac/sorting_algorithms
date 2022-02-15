#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Shell sort algorithm in C
 *
 * @array: Array need to be sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1;
	int swap, inner;
	size_t out;

	if (!array || size < 2)
		return;

	while ((size_t)interval < size / 3)
		interval *= 3 + 1;

	while (interval > 0)
	{
		for (out = interval; out < size; out++)
		{
			swap = array[out];
			inner = out;

			while (inner > interval - 1 && array[inner - interval] >= swap)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}
			array[inner] = swap;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
