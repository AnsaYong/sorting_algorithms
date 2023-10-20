#include <stdio.h>
#include "sort.h"


/**
 * selection_sort - implementation of the selection sort algorithm
 * @array: the array to be sorted
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;	/* to store array indices */
	int temp;			/* to store array data */

	/* loop through the entire array */
	for (i = 0; i < size - 1; i++)
	{
		min = i;	/* assume the current index has the least value */

		/* find the smallest number between array[i] and array[n - 1] */
		for (j = i + 1; j < size; j++)
		{
			/* smallest number by comparing the 2 successive numbers */
			if (array[j] < array[min])
			{
				/* update index with smallest number accordingly */
				min = j;
			}
		}
		/* Swap smallest number with array[i] */
		if (min != i)
		{
			/* swap value at index i with value at the new index */
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}

		/* Print the array after each swap */
		print_array(array, size);
	}
}
