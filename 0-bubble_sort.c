#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * Description: function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * Return: nothing(void)
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	/* Outer loop iterates through the array elements */
	for (i = 0; i < size - 1; i++)
	{
		/* Inner loop iterates through the remaining unsorted elements */
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
