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
 * shell_sort - shell sort algorithm of ints in ascending order
 * @array: array of ints
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t q, g, r;

	if (array == NULL || size < 2)
		return;
	for (q = 1; q < (size / 3);)
		q = q * 3 + 1;
	for (; q >= 1; q /= 3)
	{
		for (g = q; g < size; g++)
		{
			r = g;
			while (r >= q && array[r - q] > array[r])
			{
				swap_ints(array + r, array + (r - q));
				r -= q;
			}
		}
		print_array(array, size);
	}
}	
