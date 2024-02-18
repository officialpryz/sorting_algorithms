#include "sort.h"

/**
 * getMax - Get the maximum value in an array
 * @array: The array to be checked
 * @size: Size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * countingSort - Sort an array using counting sort
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: Exponent
 */
void countingSort(int *array, size_t size, int exp)
{
	const int base = 10;
	int *output = malloc(sizeof(int) * size);
	int *count = malloc(sizeof(int) * base);

	size_t i;

	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; (int)i < base; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % base]++;
	}

	for (i = 1; (int)i < base; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(output);
	free(count);
}

/**
 * radix_sort - Sort an array using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
