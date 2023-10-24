#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int temp;

	/* Validate the array and its size */
	if (!array || size < 2)
		return;

	/* Generate the Knuth sequence */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	/**
	 * Checks elements at intervals apart and swap them if the
	 * element on the left is greater than the element on the right
	 */
	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}

		print_array(array, size);

		/* Reduces the intervel between the elements */
		interval /= 3;
	}
}
