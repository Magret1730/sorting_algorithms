#include "sort.h"
#include <stdbool.h>

/**
 * _swap - function swaps element in an array
 * @num1: pointer to the first element
 * @num2: pointer to the second element
 * Return: nothing
 */
void _swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * partition - Partitions the array using Lomuto scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element.
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high]; /* pivot is the last element*/
	int i = low - 1; /* Index of smaller element */
	int j = high + 1;

	while (i < (int)size)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i < j)
		{
			_swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else if (i >= j)
			break;
	}
	/*print_array(array, size);*/
	return (i);
}

/**
 * _sort - Recursive function to perform quick sort.
 * @array: Array to be sorted.
 * @low: Starting index of the subarray.
 * @high: Ending index of the subarray.
 * @size: Size of the array.
 * Return: nothing
 */
void _sort(int *array, int low, int high, size_t size)
{
	size_t index;

	if (low < high)
	{
		index = partition(array, low, high, size);
		_sort(array, low, index - 1, size);
		_sort(array, index, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using the quicksort hoare algorithm
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (array == NULL || size <= 1)
		return;
	_sort(array, low, high, size);
	/*print_array(array, size);*/
}
