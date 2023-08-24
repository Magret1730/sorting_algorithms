#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * Description: function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list of integers
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;;
	listint_t *insertion;
	listint_t *next_current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
		/**
		 * if (previous->n > previous->next->n)
			temp = *list;
			current = previous->next;
			previous->next = current->next;
			previous->n = current->n;
			previous->prev = NULL;
 			current->next = temp->next;
			current->n = temp->n;
			current->prev = previous;
			temp = previous;
			print_list(list);
	*/
	while (current != NULL)
	{
		insertion_point = current->prev;
		next_current = current->next;
		/* Traverse backwards to find the correct position for insertion*/
		while (insertion_point != NULL && insertion_point->n > current->n)
			insertion_point = insertion_point->prev;
		/*Updatepointers to insert the current node into the correct position*/
		if (insertion_point == NULL)
		{
			(*list)->prev = current;
			current->next = *list;
			current->prev = NULL;
			*list = current;
		}
		else
		{
			insertion_point->next->prev = current;
			current->next = insertion_point->next;
			insertion_point->next = current;
			current->prev = insertion_point;
		}
		current = next_current;
		print_list(*list)
	}
}
/**
 * 1. Get the list
 * 2. return if it is empty
 * 3. Compare the second element in the list with the first element
 * 	if the first element is smaller, SWAP.
 * 4. Compare the third element in the list with second element
 * 	if it is smaller than the second element, SWAP
 * 5. Compare the second element in the list,
 * 	if it smaller with the first, SWAP
 */
