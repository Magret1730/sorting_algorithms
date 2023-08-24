#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * Description: function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of the linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	sorted = NULL;  /* Initialize sorted list as empty*/
	current = *list; /* Take the first node from the unsorted list*/
	while (current != NULL)
	{
		next = current->next; /*Save the next node before modifying links*/
		if (sorted == NULL || sorted->n >= current->n)
		{
			/*Insert current node at the beginning of the sorted list*/
			current->prev = NULL;
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			/*Find the correct position in the sorted list to insert the current node*/
			temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;
			/*Insert current node after temp*/
			current->prev = temp;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
		}
		print_list(sorted); /*Print the list after each insertion*/
		current = next; /*Move to the next unsorted node*/
	}
	*list = sorted; /*Update the original list head to point to the sorted list*/
}
