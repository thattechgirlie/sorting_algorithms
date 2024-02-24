#include "sort.h"
/**
 * swap_ints - swap int in array
 * @a: int 1
 * @b: int 2
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - selection algorithm in ascending order
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t g, m;

	if (array == NULL || size < 2)
		return;
	for (g = 0; g < size - 1; g++)
	{
		min = array + 1;
		for (m = g + 1; m < size; m++)
			min = (array[m] < *min) ? (array + m) : min;
		if ((array + g) != min)
		{
			swap_ints(array + g, min);
			print_array(array, size);
		}

	}
}
