#include <stdio.h>
#include "main.h"

/**
 * clear_bit - function that sets the value of a bit to 0 at a given index
 *
 *@n: Unsigned long interger to set at index.
 *
 *@index: 1 if it worked, or -1 if an error occurred
 *
 * Return: THe number converted.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int maxIndex = sizeof(unsigned long int) * 8 - 1;
	unsigned long int mask;

	if (index > maxIndex)
	{
		return (-1);
	}

	mask = 1UL << index;

	*n &= ~mask;

	return (1);
}
