#include <stdio.h>

/**
 * print_binary - converts a decimal number to binary and prints the binary.
 *
 * @n: Unsigned long interger to pirint.
 *
 * Return: THe number converted.
 */

void print_binary(unsigned long int n)
{

	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int bit_count = sizeof(unsigned long int) * 8;

	while (bit_count > 0)
	{

		if (n & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;

		bit_count--;
	}
}
