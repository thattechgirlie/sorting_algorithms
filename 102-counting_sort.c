#include "sort.h"
/**
 * get_max - maximum value of integers in array
 * @array: array of integers
 * @size: size of array
 */
int get_max(int *array, int size)
{
	int max, a;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}
	return (max);
}

/**
 * counting_sort -  this is the counting sort algorithm
 * @array: array of integers
 * @size: size of integers
 */
void counting_sort(int *array, size_t size)
{
	int *ct, *sort, max, a;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) *size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	ct = malloc(sizeof(int) *max + 1);
	if (ct == NULL)
	{
		free(sort);
		return;
	}
	for (a = 0; a < (max + 1); a++)
		ct[a] = 0;
	for (a = 0; a < (int)size; a++)
		ct[array[a]] += 1;
	for (a = 0; a < (max + 1); a++)
		ct[a] += ct[a - 1];
	print_array(ct, max + 1);
	for(a = 0; a < (int)size; a++)
	{
		sort[ct[array[a]] - 1] = array[a];
		ct[array[a]] -= 1;
	}
	for (a = 0; a < (int)size; a++)
		array[a] = sort[a];
	free(sort);
	free(ct);
}
