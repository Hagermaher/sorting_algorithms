#include "sort.h"

/**
 * swap_ints - Swap two integer
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - order a subset of array
 * @array: array
 * @size: size
 * @left: starting index
 * @right: ending index
 *
 * Return: final index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pvot, abve, blow;

	pvot = array + right;
	for (abve = blow = left; blow < right; blow++)
	{
		if (array[blow] < *pvot)
		{
			if (abve < blow)
			{
				swap_ints(array + blow, array + abve);
				print_array(array, size);
			}
			abve++;
		}
	}
	if (array[abve] > *pvot)
	{
		swap_ints(array + abve, pvot);
		print_array(array, size);
	}
	return (abve);
}

/**
 * lomuto_sort - implementing the quicksort
 * @array: array
 * @size: array
 * @left: starting index
 * @right: ending index
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, prt - 1);
		lomuto_sort(array, size, prt + 1, right);
	}
}

/**
 * quick_sort - sorts an array of integer
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto_sort(array, size, 0, size - 1);
}
