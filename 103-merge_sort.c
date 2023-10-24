#include "sort.h"

/**
 * merge_subarr - Creates two subarrays of *array.
 * Sorts them and then merges them again.
 * @arr: The array to be sorted
 * @left_idx: The start of the first subarray
 * @mid_idx: End of the first subarray
 * @right_idx: End of the second subarray
 */
void merge_subarr(int *arr, size_t left_idx, size_t mid_idx, size_t right_idx)
{
	printf("Merging...\n");
	printf("[left]: ");
	printArray(arr, left_idx, mid_idx);
	printf("[right]: ");
	printArray(arr, mid_idx + 1, right_idx);

	merge(arr, left_idx, mid_idx, right_idx);

	printf("[Done]: ");
	printArray(arr, left_idx, right_idx);
}

/**
 * merge - Combines two subarrays
 * @arr: The array to be sorted
 * @left_idx: The start of the first subarray
 * @mid_idx: End of the first subarray
 * @right_idx: End of the second subarray
 */
void merge(int *arr, size_t left_idx, size_t mid_idx, size_t right_idx)
{
	size_t i, j, k, n1 = mid_idx - left_idx + 1, n2 = right_idx - mid_idx;
	int *temp_arr = malloc((n1 + n2) * sizeof(int));

	if (temp_arr == NULL)
		return;
	for (i = 0; i < n1; i++)	/* Copy data to temp arrays */
		temp_arr[i] = arr[left_idx + i];
	for (j = 0; j < n2; j++)
		temp_arr[n1 + j] = arr[mid_idx + 1 + j];

	i = 0, j = n1, k = left_idx;
	while (i < n1 && j < (n1 + n2))	/* Merge subarrays back */
	{
		if (temp_arr[i] <= temp_arr[j])
		{
			arr[k] = temp_arr[i];
			i++;
		}
		else
		{
			arr[k] = temp_arr[j];
			j++;
		}
		k++;
	}
	while (i < n1)	/* Copy the remaining elements of left arr */
	{
		arr[k] = temp_arr[i];
		i++;
		k++;
	}
	while (j < (n1 + n2))	/* Copy the remaining elements of left arr */
	{
		arr[k] = temp_arr[j];
		j++;
		k++;
	}
	free(temp_arr);
}

/**
 * merge_sort - sorts an array of numbers using the
 * merge ort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array to be sorted/
 */
void merge_sort(int *array, size_t size)
{
	size_t right_idx;

	if (array == NULL || size < 2)
		return;

	right_idx = size - 1;

	_sort(array, 0, right_idx);
}

/**
 * _sort - sorts an array of numbers using the
 * merge ort algorithm - repeatedly splits the
 * array and calls itself to sort.
 * @array: The array to be sorted
 * @start_idx: The left index of the array
 * @end_idx: Right index on the array
 */
void _sort(int *array, size_t start_idx, size_t end_idx)
{
	size_t mid_idx;

	if (start_idx < end_idx)
	{
		mid_idx = (start_idx + end_idx) / 2;

		_sort(array, start_idx, mid_idx);	/* Sort first half */
		_sort(array, mid_idx + 1, end_idx);    /* Sort second half */

		merge_subarr(array, start_idx, mid_idx, end_idx);
	}
}

/**
 * printArray - Prints an array
 * @arr: Array to be printed
 * @left_idx: Left index
 * @right_idx: Right index
 */
void printArray(int *arr, size_t left_idx, size_t right_idx)
{
	size_t i;

	for (i = left_idx; i <= right_idx; i++)
	{
		printf("%d", arr[i]);
		if (i < right_idx)
			printf(", ");
	}
	printf("\n");
}
