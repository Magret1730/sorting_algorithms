#include "sort.h"

/**
 * nodes_swap - function that swaps two nodes
 * in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void nodes_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Update next pointers*/
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;

	/* Update prev pointers*/
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly
 * linked list of integers using
 * the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *iter, *insert, *temp;

	/*checks if the input list is NULL, empty*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	iter = (*list)->next; /* Start from the second element*/

	while (iter != NULL)
	{
		temp = iter->next;
		insert = iter->prev;

		/* Compare and swap nodes as needed*/
		while (insert != NULL && iter->n < insert->n)
		{
			nodes_swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}

		iter = temp; /* Move to the next element*/
	}
}

