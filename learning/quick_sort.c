#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomuto_partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
            /* Print array after each swap*/
            print_array(array, high + 1);
        }
    }

    swap(&array[i + 1], &array[high]);
    /* Print array after pivot placement*/
    print_array(array, high + 1);

    return i + 1;
}

void quick_sort_recursive(int *array, int low, int high)
{
	int partition_index;
    	if (low < high)
	{
        partition_index = lomuto_partition(array, low, high);
        quick_sort_recursive(array, low, partition_index - 1);
        quick_sort_recursive(array, partition_index + 1, high);
    }
}

void quick_sort(int *array, size_t size) {
    quick_sort_recursive(array, 0, size - 1);
}
