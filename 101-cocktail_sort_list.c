#include "sort.h"
/**
 * swap_fwd - Handles swapping during forward moves
 * @list: pointer to address of first node of the DLL
 * @curr_node: this is the middle node btwn next & trailing nodes
 * it should not be lower than prev_node
 * @trail_node: This is the node behind the current node
 * should not be greater than curr_node
 * @nxt_node: the node after the two nodes to be compared (prev & curr)
 * @swapped: pointer to the address of where swap val. is saved
 */
void swap_fwd(
		listint_t **list, listint_t *curr_node,
		listint_t *trail_node, listint_t *nxt_node, int *swapped)
{
	if (trail_node->n > curr_node->n)
	{
		trail_node->next = nxt_node;
		if (nxt_node)
			nxt_node->prev = trail_node;
		curr_node->next = trail_node;
		curr_node->prev = trail_node->prev;
		if (!(trail_node->prev))
		{
			(*list) = curr_node;
		} else
		{
			trail_node->prev->next = curr_node;
		}
		trail_node->prev = curr_node;
		print_list((*list));
		*swapped = 1;
	}
}

/**
 * swap_bkwd - Perfroms swaps as we move backward
 * @list: pointer to the address of the first node of doubly linked_list
 * @curr_node: node ahead of trail_node, should be less than nxt_node
 * @trail_node: It is behind curr_node and helps during swappping. It acts as
 * nxt_node in swap_fwd fxn
 * @nxt_node: It is ahead of curr_node and should be less curr_node
 * @swapped: pointer to the address of where swapped val. is saved
 * @inner_switch: pointer to the address where inner_switch is saved
 * inner_switch notifies us if a swap occured, if it didn't we maintain
 * curr_node
 */
void swap_bkwd(
		listint_t **list, listint_t *curr_node,
		listint_t *trail_node, listint_t *nxt_node,
		int *swapped, int *inner_switch)
{
	if (nxt_node && (curr_node->n < nxt_node->n))
	{
		nxt_node->next = trail_node;
		trail_node->prev = nxt_node;
		curr_node->next = nxt_node;
		curr_node->prev = nxt_node->prev;
		if (!(nxt_node->prev))
		{
			(*list) = curr_node;
		} else
		{
			nxt_node->prev->next = curr_node;
		}
		nxt_node->prev = curr_node;
		print_list((*list));
		*inner_switch = 1;
		*swapped = 1;
	}
}


/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail shaker
 * sort algprithm. This algorithm is an extension of bubble sort
 *
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int inner_switch, swapped = 1;
	listint_t *curr_node, *trail_node, *nxt_node;

	if (!list || !(*list) || !((*list)->next))
		return;
	while (swapped)
	{
		swapped = 0;
		curr_node = (*list)->next;
		while (curr_node)
		{
			nxt_node = curr_node->next;
			trail_node = curr_node->prev;
			swap_fwd(list, curr_node, trail_node, nxt_node, &swapped);
			curr_node = nxt_node;
		}
		if (!swapped)
			break;
		swapped = 0;
		if (!(trail_node->next))
			curr_node = trail_node->prev;
		else
			curr_node = trail_node;
		while (curr_node)
		{
			inner_switch = 0;
			trail_node = curr_node->next;
			nxt_node = curr_node->prev;
			swap_bkwd(list, curr_node, trail_node, nxt_node, &swapped, &inner_switch);
			if (inner_switch == 0)
				curr_node = nxt_node;
		}
	}
}
