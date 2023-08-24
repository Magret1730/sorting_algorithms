#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, smallest_num;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest_num = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_num])
				smallest_num = j;
		}
		if (array[smallest_num] != array[i])
		/*if (smallest_num != 1)*/
		{
			temp = array[i];
			array[i] = array[smallest_num];
			array[smallest_num] = temp;
			print_array(array, size);
		}
	}
}
