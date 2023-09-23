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

	if (!list || !(*list))
		return;
	/* indicates that only one elem in list, therefore sorted */
	if (!((*list)->next))
	{
		print_list(*list);
		return;
	}
	curr_node = (*list)->next;
	while (curr_node)
	{
		comp_val = curr_node->n;
		prev_node = curr_node->prev;
		nxt_node = curr_node->next;

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
		curr_node = curr_node->next;
	}
}
