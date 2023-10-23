#include "sort.h"

/**
 * counting_sort - Implementation of the counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0, index = 1;
	int *count_array = NULL, *temp_array = NULL;

	if (!array || size < 2)
		return;

	max_value = array[0];
	while (index < (int) size)
	{
		if (array[index] > max_value)
			max_value = array[index];
		index++;
	}

	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;

	count_array = malloc(sizeof(int) * max_value + 1);
    if (count_array == NULL)
	{
		free(temp_array);
		return;
	}

	for (index = 0; index <= max_value; ++index)
		count_array[index] = 0;
	for (index = 0; index < (int) size; ++index)
		count_array[array[index]]++;
	for (index = 1; index <= max_value; ++index)
		count_array[index] = count_array[index - 1] + count_array[index];

    print_array(count_array, max_value + 1);

	for (index = 0; index < (int) size; ++index)
	{
		temp_array[count_array[array[index]] - 1] = array[index];
		count_array[array[index]]--;
	}
	for (index = 0; index < (int) size; ++index)
		array[index] = temp_array[index];

	free(count_array);
	free(temp_array);
	count_array = temp_array = NULL;
}
