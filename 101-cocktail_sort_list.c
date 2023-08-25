#include "sort.h"
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * Description: function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: list to be sorted
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *current = *list;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0; /* Traverse forward through the list */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				temp = current->next; /*Swap elements*/
				current->next = temp->next;
				temp->next = current;
				if (current->prev)
					current->prev->next = temp;
				else
					*list = temp;
				temp->prev = current->prev;
				current->prev = temp;
				if (current->next)
					current->next->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped) /* Break if no swaps occurred */
			break;
		swapped = 0;
		current = current->prev;
		while (current->prev != NULL) /* Traverse backward through the list */
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev; /*Swap elements*/
				current->prev = temp->prev;
				temp->prev = current;
				if (current->next)
					current->next->prev = temp;
				else
					*list = temp;
				temp->next = current->next;
				current->next = temp;
				if (current->prev)
					current->prev->next = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	} while (swapped);
}
