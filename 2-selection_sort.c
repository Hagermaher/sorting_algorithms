#include "sort.h"
/**
 * selection_sort -  sorts an array
 * @array: array
 * @size: array
*/

void selection_sort(int *array, size_t size)
{
	size_t w, k, kmin = 0;
	int tmp;

	tmp = 0;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (w = 0; w < size - 1; w++)
	{
		kmin = w;
		for (k = w + 1; k < size; k++)
		{
			if (array[k] < array[kmin])
			{
				kmin = k;
			}
		}
		if (kmin != w)
		{
			tmp = array[w];
			array[w] = array[kmin];
			array[kmin] = tmp;
			print_array(array, size);
		}
	}
}
