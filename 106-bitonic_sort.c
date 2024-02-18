#include "sort.h"

void bitonic_recursive(int *array, size_t size, int dir, size_t bit_size);
void bitonic_merge(int *array, size_t size, int dir);

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm.
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursive(array, size, 1, size);
}

/**
 * bitonic_recursive - recursive function to perform bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 * @dir: direction (1 for ascending, 0 for descending)
 * @bit_size: size of the bitonic sequence
 */
void bitonic_recursive(int *array, size_t size, int dir, size_t bit_size)
{
	size_t half = size / 2;

	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, bit_size, \
			(dir == 1) ? "UP" : "DOWN");
	print_array(array, size);

	bitonic_recursive(array, half, 1, bit_size);
	bitonic_recursive(array + half, half, 0, bit_size);

	bitonic_merge(array, size, dir);
	printf("Result [%lu/%lu] (%s):\n", size, bit_size, \
			(dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_merge - merges two arrays in a specific order
 * @array: array to be sorted
 * @size: size of the array
 * @dir: direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t half = size / 2;
	size_t i;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < half; i++)
	{
		if ((array[i] > array[i + half]) == dir)
		{
			tmp = array[i];
			array[i] = array[i + half];
			array[i + half] = tmp;
		}
	}
}
