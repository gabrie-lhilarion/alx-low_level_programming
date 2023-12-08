#include <stdio.h>
#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index..
 *
 * @n: Unsigned long interger to set at index.
 *
 *@index: is the index, starting from 0 of the bit you want to set
 *
 * Return: THe number converted.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int maxIndex = sizeof(unsigned long int) * 8 - 1;
	unsigned long int mask;

	if (index > maxIndex)
	{
		return (-1);
	}

	mask = 1UL << index;
	*n |= mask;

	return (1);
}
