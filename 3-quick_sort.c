#include "sort.h"
/**
 * swap_ints - swapping ints in an array
 * @a: first to swap
 * @b: second int to swap
 */
void swap_ints(int *a, int *b)
{
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * quick_sort - quicksort algorithm for ints in ascending order
 * @array: array of ints
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsort(array, size, 0, size - 1);
}
