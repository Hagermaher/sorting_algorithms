#include "sort.h"

/**
 * shell_sort - sorts an array of integers
 * @array: array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	unsigned int w, k, jap;
	int tmp;

	jap = 0;
	tmp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (jap < size / 3)
	{
		jap = jap * 3 + 1;
	}
	for (; jap > 0; jap = (jap - 1) / 3)
	{
		for (w = jap; w < size; w++)
		{
			tmp = array[w];
			for (k = w; k >= jap && array[k - jap] > tmp; k -= jap)
			{
				array[k] = array[k - jap];
			}
			array[k] = tmp;
		}
		print_array(array, size);
	}
}
