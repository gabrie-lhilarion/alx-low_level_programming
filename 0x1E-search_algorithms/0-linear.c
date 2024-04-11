#include <stdio.h>

/**
 * linear_search - prints number of arguments passed into it.
 * @array: array to search
 * @size: size of the array
 * @value: value to find
 * Return: value if found otherwise -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%ld]\n",
			   (unsigned long)i, (long)array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}
