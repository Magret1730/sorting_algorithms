#include "sort.h"

/**
 * count_sort - function that sorts an array of integers
 * Description: function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */
void count_sort(int *array, size_t size, int position, int k)
{
	int i, *count_array, *new_array;

	if (array == NULL || size <= 1)
		return;
	/**k = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}*/
	count_array = (int *)malloc((k + 1) * sizeof(int));
	if (count_array == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i <= k; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[(array[i] / position) % 10]++;
	for (i = 1; i <= k; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	/*print_array(count_array, k + 1);*/
	new_array = (int *)malloc(size * sizeof(int));
	if (new_array == NULL)
	{
		free(count_array);
		exit(EXIT_FAILURE);
	}
	for (i = (int)size - 1; i >= 0; i--)
		new_array[--count_array[(array[i] / position) % 10]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
	free(new_array);
	free(count_array);
}

/**
 * radix_sort - function that sorts an array of integers
 * Description: function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: array to be sorted
 * @size: number of element in array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int position, k, i;

	k = array[0]; /* k = maximum number */
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
        }
	for (position = 1; k / position > 0; position *= 10)
	{
		count_sort(array, size, position, k);
		print_array(array, size);
	}
	/*print_array(array, size);*/
}
