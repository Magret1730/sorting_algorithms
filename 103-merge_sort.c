#include "sort.h"

/**
 * merge_subarray - function that sorts a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @left: The left index of the array.
 * @mid: The middle index of the array.
 * @right: The right index of the array.
 */
void merge_subarray(int *subarray, int *buff, size_t left,
size_t mid, size_t right)
{
	size_t i, j;
	size_t k = 0;

	/* Prints the subarrays that are being merged*/
	printf("Merging...\n[left]: ");
	print_array(subarray + left, mid - left);

	printf("[right]: ");
	print_array(subarray + mid, right - mid);

	/* loops to compare and merge the two subarrays*/
	while (i < mid && j < right)
	{
		buff[k++] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	}

	while (i < mid)
	{
		buff[k++] = subarray[i++];
	}
	while (j < right)
	{
		buff[k++] = subarray[j++];
	}

	/* copy the sorted subarray back to the original subarr.*/
	for (i = left, k = 0; i < right; i++)
	{
		subarray[i] = buff[k++];
	}

	printf("[Done]: ");
	print_array(subarray + left, right - left);
}

/**
 * merge_sort_recursion - function that implement
 * the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @left: The left index of the subarray.
 * @right: The right index of the subarray.
 */
void merge_sort_recursion(int *subarray, int *buffer,
size_t left, size_t right)
{
	size_t mid;

	/* Check if the subarray has more than one element to sort*/
	if (right - left > 1)
	{
		/*Calculate the middle index*/
		mid = left + (right - left) / 2;

		/* sort the left and right halves of subarray recursively*/
		merge_sort_recursion(subarray, buffer, left, mid);
		merge_sort_recursion(subarray, buffer, mid, right);
		merge_subarray(subarray, buffer, left, mid, right);
	}
}

/**
 * merge_sort - function that sort an array of integers
 * in ascending order using
 * the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	/* Check if the array is NULL or has fewer than 2 elements*/
	if (array == NULL || size < 2)
		return;

	/* Allocate memory to buffer for sorting processes*/
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	/* merge_sort_recursion start the sorting process*/
	merge_sort_recursion(array, buffer, 0, size);

	/* Free the buffer memory when sorting is over*/
	free(buffer);
}
