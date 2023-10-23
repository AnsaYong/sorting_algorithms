#include <stdio.h>
#include "sort.h"


/**
 * swap - swaps two numbers
 * @a: first number
 * @b: second number
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: Array to be sorted
 * @low: Index of smaller element
 * @high: Index of the pivot
 *
 * Return: Index of the new pivot
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];	/* Choose the last element as pivot */
	int i = low - 1;            /* Initialize index of the smaller element */
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively calls quick sort
 * @array: array to be sorted
 * @low: Index of smaller element
 * @high: Index of pivot
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		print_array(array, high + 1);
		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Implementation of the quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1);
}
