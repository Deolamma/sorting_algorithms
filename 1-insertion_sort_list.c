#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 *
 * @list: pointer to address where list is saved in memory
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *prev_node, *nxt_node;
	int comp_val;
	/* return if a single or no element is in the list */
	/* if list is NULL also return */
	if (!list || !(*list) || (!(*list)->next))
		return;
	/* set current node to the second node of the list */
	curr_node = (*list)->next;
	while (curr_node)
	{
		comp_val = curr_node->n;
		prev_node = curr_node->prev;
		nxt_node = curr_node->next;

		/* Continue to swap until we get to the start of list OR */
		/* prev_node's value is less than curr_node */
		while (prev_node && ((prev_node->n) > comp_val))
		{
			prev_node->next = nxt_node;
			if (nxt_node)
				nxt_node->prev = prev_node;
			curr_node->next = prev_node;
			curr_node->prev = prev_node->prev;

			if (prev_node->prev)
			{
				prev_node->prev->next = curr_node;
			} else
				(*list) = curr_node;

			prev_node->prev = curr_node;
			prev_node = curr_node->prev;
			nxt_node = curr_node->next;
			print_list(*list);
		}
		/* move to the next node */
		curr_node = curr_node->next;
	}
}
