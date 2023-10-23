#include <stdio.h>
#include "sort.h"


/**
 * lomuto_partition - Implementation of the Lomuto partition scheme
 * @array: Array to be sorted
 * @lo: Index of the smaller element
 * @hi: Index of the pivot
 * 
 * Return: The position of the pivot element
*/
size_t lomuto_partition(int *array, size_t lo, size_t hi)
{
    int pivot = array[hi];  /* Choose the last element as pivot */
    size_t i = lo;          /* Initialize the index of the smaller element */
    size_t j;
    int temp;

    for (j = lo; j < hi; j++)
    {
        if (array[j] <= pivot)
        {
            /* swap array[i] and array[j] */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;            /* Increment index of the smaller element */
        }
    }

    /* Swap array[i] and the pivot */
    temp = array[i];
    array[i] = array[hi];
    array[hi] = temp;

    /* Return the position of the pivot element */
    return (i);
}


/**
 * quick_sort - Implementation of the quick sort algorithm
 * @array: The array to be sorted
 * @size: Size of @array
*/
void quick_sort(int *array, size_t size)
{
    size_t pivot_idx;

    if (size < 2)
        return;         /* Base case: Assume already sorted */

    /* Use Lomuto partition to find the pivot element's position */
    pivot_idx = lomuto_partition(array, 0, size - 1);

    /* Recursively sort the left and right sub arrays */
    if (pivot_idx > 0)
        quick_sort(array, pivot_idx);

    if (pivot_idx < size - 1)
        quick_sort(array + pivot_idx + 1, size - pivot_idx - 1);
}
