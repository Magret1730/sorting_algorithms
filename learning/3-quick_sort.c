#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * Description: function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int pivot;

	if (size <= 1) /* Base case: Array of size 0 or 1 is already sorted */
		return;
	pivot = array[size - 1]; /*last element in array*/
	i = -1; /* Index for elements smaller than the pivot */
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++; /* Increment the index for smaller elements */
			temp = array[i]; /* Swap elements at indices i and j*/
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size); /*Print array after each swap*/
		}
	}
	/* Put the pivot in its correct sorted position */
	temp = array[i + 1];
	array[i + 1] = array[size - 1];
	array[size - 1] = temp;
	print_array(array, size); /*Print array after pivot placement*/

	/*Recursively sort the subarrays*/
	quick_sort(array, i + 1); /*Elements smaller than pivot*/
	quick_sort(array + i + 1, size - (i + 1)); /*Elements greater than pivot*/
}
