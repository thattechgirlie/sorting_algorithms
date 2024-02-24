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
 * bubble_sort - sorts from greatest element first
 * @array: arrays to sort
 * @size: represents size of array *
 */
void bubble_sort(int *array, size_t size)
{
	size_t g, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (g = 0; g < len - 1; g++)
		{
			if (array[g] > array[g + 1])
			{
				swap_ints(array + g, array + g + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
