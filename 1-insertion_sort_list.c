#include "sort.h"

/**
 * insertion_sort_list - Sort list with insertion algorithm
 * @list: The double linked list to be sorted
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *position_node, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	/* Assign head node from the double linked list to current node */
	current = (*list);

	while (current)
	{
		/* Assign the current node to positional node for traversing and swapping */
		position_node = current;

		while (position_node->prev && position_node->n < position_node->prev->n)
		{
			temp = position_node->prev;
			position_node->prev = temp->prev;

			/* Update the next pointer of the previous node to point to position_node */
			if (temp->prev)
				temp->prev->next = position_node;
			else
				/* If position_node becomes the new head, update the list pointer */
				*list = position_node;

			temp->next = position_node->next;
			if (temp->next)
				/* Assigns temp node to the prev pointer of the next node to temp */
				temp->next->prev = temp;
			/* Assigns temp to position node after it shifted to the left*/
			position_node->next = temp;
			/* Assigns position node to the prev pointer of temp node */
			temp->prev = position_node;

			print_list(*list); /* Prints list at each swap */
		}
		current = current->next;
	}
}
