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
	size_t i, j, k;
	size_t n1 = mid_idx - left_idx + 1;
	size_t n2 = right_idx - mid_idx;

	/* Create a temp integer array */
	int *temp_arr = malloc((n1 + n2) * sizeof(int));
	if (temp_arr == NULL)
		return;

	/* Copy data to temp arrays */
	for (i = 0; i < n1; i++)
		temp_arr[i] = arr[left_idx + i];
	for (j = 0; j < n2; j++)
		temp_arr[n1 + j] = arr[mid_idx + 1 + j];

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < n1; i++)
	{
		printf("%d", temp_arr[i]);
		if (i < n1 - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (j = n1; j < n1 + n2; j++)
	{
		printf("%d", temp_arr[j]);
		if (j < n1 + n2 - 1)
			printf(", ");
	}
	printf("\n");

	/* Merge the temp arrays back into arr[left_idx...right_idx] */
	i = 0;			/* Initital index of first subarray */
	j = n1;			/* Initial index of second subarray */
	k = left_idx;	/* Initial index of merged subarray */
	while (i < n1 && j < (n1 +n2))
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

	/* Copy the remaining elements of left_arr[], if there are any */
	while (i < n1)
	{
		arr[k] = temp_arr[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of right_arr[], if there are any */
	while (j < (n1 + n2))
	{
		arr[k] = temp_arr[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	for (i = left_idx; i <= right_idx; i++)
	{
		printf("%d", arr[i]);
		if (i < right_idx)
			printf(", ");
	}
	printf("\n");

	free(temp_arr);
}

/**
 * merge_sort - sorts an array of numbers using the
 * merge ort algorithm.
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
