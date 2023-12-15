#include "sort.h"

/**
 * get_max - Get the maximum value
 * @array: array
 * @size: size
 *
 * Return: maximum integer
 */
int get_max(int *array, int size)
{
	int max, w;

	for (max = array[0], w = 1; w < size; w++)
	{
		if (array[w] > max)
			max = array[w];
	}

	return (max);
}

/**
 * counting_sort - Sort an array
 * @array: array
 * @size: size
 *
 * Description: Prints the counting array
 */
void counting_sort(int *array, size_t size)
{
	int *cunt, *sortd, max, w;

	if (array == NULL || size < 2)
		return;

	sortd = malloc(sizeof(int) * size);
	if (sortd == NULL)
		return;
	max = get_max(array, size);
	cunt = malloc(sizeof(int) * (max + 1));
	if (cunt == NULL)
	{
		free(sortd);
		return;
	}

	for (w = 0; w < (max + 1); w++)
		cunt[w] = 0;
	for (w = 0; w < (int)size; w++)
		cunt[array[w]] += 1;
	for (w = 0; w < (max + 1); w++)
		cunt[w] += cunt[w - 1];
	print_array(cunt, max + 1);

	for (w = 0; w < (int)size; w++)
	{
		sortd[cunt[array[w]] - 1] = array[w];
		cunt[array[w]] -= 1;
	}

	for (w = 0; w < (int)size; w++)
		array[w] = sortd[w];

	free(sortd);
	free(cunt);
}
