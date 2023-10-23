#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a linked list using the cocktail shaker sort
 * algorithm.
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped, temp;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current;

	do {
		swapped = 0;

		/* Forward pass (bubble sort from left to right) */
		current = start ? start->next : *head;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				/* swap the data */
				temp = current->n;
				current->n = current->next->n;
				current->next->n = temp;
				swapped = 1;

				/* Peint the list after the swap */
				print_list
