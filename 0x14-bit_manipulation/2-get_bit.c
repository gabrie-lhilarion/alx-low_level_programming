#include <stdio.h>
#include "main.h"

/**
 * get_bit -  function that returns the value of a bit at a given index.
 * @n:  unsigned long integer
 * @index: is the index, starting from 0 of the bit you want to get
 * Return: val
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int maxIndex = sizeof(unsigned long int) * 8 - 1;
	unsigned long int mask;
	int bitValue;

	if (index > maxIndex)
	{
		return (-1);
	}

	mask = 1UL << index;
	bitValue = (n & mask) ? 1 : 0;

	return (bitValue);
}
