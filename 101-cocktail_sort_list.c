#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * using the cocktail shaker sort algorithm.
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int direction = FORWARD;
	listint_t *start = NULL, *end = NULL, *current = *list;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	start = current;
	end = get_end_node(*list);
	while (start != end)
	{
		if (current->n == current->next->n)
			break;
		else if (current->n > current->next->n && direction == FORWARD)
		{
			_swap(list, current);
			print_list(*list);
		}
		else if (current->next->n < current->n && direction == BACKWARD)
		{
			_swap(list, current);
			current = current->prev;
			print_list(*list);
		}
		else if (direction == FORWARD)
			current = current->next;
		else if (direction == BACKWARD)
			current = current->prev;
		if (direction == BACKWARD && current->next == start)
		{
			direction = FORWARD;
			current = current->next;
		}
		if (direction == FORWARD && current->prev == end)
		{
			end = end->prev;
			direction = BACKWARD;
			current = current->prev;
		}
	}
}

/**
 * get_end_node - gets the address of the last node
 * in the doubly linked list to be sorted.
 * @head: The doubly linked lis to be sorted
 */
listint_t *get_end_node(listint_t *h)
{
	listint_t *current = h;

	while (current->next != NULL)
	{
		current = current->next;
	}

	return (current);
}

/**
 * _swap - Swap two nodes of a doubly linked list
 * @list: The doubly linked list to be sorted - contains the nodes
 * @node: The node to be swapped with the next
 */
void _swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}
