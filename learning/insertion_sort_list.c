#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * Description: function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: list of integers
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *temp = *list;

	if (list == NULL || *list == NULL || *(list)->next == NULL)
		return;

	for (i = 0; i < sizeof(listint_t **list); i++)
	{
		if (head->n < head->next->n)
		{
			temp = head->n;
			head->n = head->next->n;
 			head->next->n = temp;

			print_list(list);
		}
	}
}
