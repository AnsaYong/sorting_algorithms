#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm
 * @array: Array of integers
 * @size: Size of the list
*/

void bubble_sort(int *array, size_t size)
{
	size_t temp, swapped, pass_throughs, j;

	/* Outter loop to pass through each item in the array */
	for (pass_throughs = 0; pass_throughs < size - 1; pass_throughs++)
	{
		swapped = 0; /* Resets swap status to zero*/

		/**
		 * Inner loop to check if current item
		 * is greater than the next item then swap
		 */
		for (j = 0; j < size - pass_throughs - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /* Set swap status to 1 meaning a swap occured */
				print_array(array, size);
			}

		}
		if (swapped == 0)
			break;
	}


}
