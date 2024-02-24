#include "sort.h"
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - uses last element as a pivot
 * @array: array of integers
 * @size: size of array
 * @left: starting index of array
 * @right: ending index of array
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *p, o, l;

	p = array + right;
	for (o = l = left; l < right; l++)
	{
		if (array[l] < *p)
		{
			if (o < l)
			{
				swap_ints(array + l, array + o);
				print_array(array, size);
			}
			o++;
		}
	}
	if (array[o] > *p)
	{
		swap_ints(array + o, p);
		print_array(array, size);
	}
	return (o);
}

/**
 * lomuto_sort - Quick sort algorithm via recursion
 * @array: array to sort
 * @size: size of array
 * @left: starting index of array
 * @right: ending index of array
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int r;

	if (right - left > 0)
	{
		r = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, r - 1);
		lomuto_sort(array, size, r + 1, right);
	}
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
	lomuto_sort(array, size, 0, size - 1);
}
