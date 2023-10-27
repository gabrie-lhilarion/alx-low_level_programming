#include <stdio.h>
#include "main.h"

/**
 * print_binary - converts a decimal number to binary and prints the binary.
 *
 * @n: Unsigned long interger to pirint.
 *
 * Return: THe number converted.
 */

void print_binary(unsigned long int n)
{

	int num_bits = sizeof(unsigned long int) * 8;
	int bit_set = 0;
	int i;

	for (i = num_bits - 1; i >= 0; i--)
	{
		unsigned long int mask = 1UL << i;

		if (n & mask)
		{
			_putchar('1');
			bit_set = 1;
		}
		else if (bit_set)
		{
			_putchar('0');
		}
	}

	if (n == 0)
	{
		_putchar('0');
	}
}
