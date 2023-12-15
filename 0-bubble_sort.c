#include "sort.h"

/**
 * bubble_sort - array sorting
 * @array: array
 * @size: size
*/
void bubble_sort(int *array, size_t size)
{
	size_t w, k, tmp;

	tmp = 0;

	if (size < 2)
	{
		return;
	}
	for (k = 0; k < size; k++)
	{
		for (w = 0; w < size - 1; w++)
		{
			if (array[w] > array[w + 1] && array[w + 1])
			{
				tmp = array[w];
				array[w] = array[w + 1];
				array[w + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
