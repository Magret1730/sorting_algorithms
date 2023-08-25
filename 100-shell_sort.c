#include "sort.h"

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
	size_t gap = 1;
	int temp;
	size_t i, j;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap /= 3;
	}
}
