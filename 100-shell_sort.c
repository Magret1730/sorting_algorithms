#include "sort.h"
/**
 * swap - function that swap two integers
 * @i: the first integer to be swapped
 * @j: the second integer to be swapped
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort
 * @array: the array of integers
 * @size: the size of array
 * Description: This function sort an array of integer
 * in ascending order using shell sort algorithm, using knuth sequence.
 */
void shell_sort(int *array, size_t size)
{
	/*initializes gap to 1*/
	size_t gap = 1;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	/*this loop calculate gap and multiply it by 3 and add 1*/
	while (gap < (size / 3))
	{
		gap = gap * 3 + 1;
	}

	while (gap >= 1)
	{
		i = gap;
		while (i < size)
		{
			j = i;
			/*
			 * this loop compared
			 * and swapped the elemnts
			 */
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
			i++;
		}
		print_array(array, size);
		gap /= 3;
	}
}
