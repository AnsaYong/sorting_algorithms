#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

#define FORWARD 1
#define BACKWARD -1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/***Prototypes***/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high);
void swap(int *a, int *b);
int partition(int *array, int low, int high);
void cocktail_sort_list(listint_t **list);
listint_t *get_end_node(listint_t *h);
void _swap(listint_t **list, listint_t *node);
void counting_sort(int *array, size_t size);
void merge_subarr(int *arr, size_t left_idx, size_t mid_idx, size_t right_idx);
void merge_sort(int *array, size_t size);
void _sort(int *array, size_t start_idx, size_t end_idx);
void merge(int *arr, size_t left_idx, size_t mid_idx, size_t right_idx);
void printArray(int *arr, size_t left_idx, size_t right_idx);

#endif	/* SORT_H */
