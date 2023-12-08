#include <stdio.h>
#include "main.h"

/**
 * xToPowerY - Raises a number to a given power.
 *
 * @base: Base of a number.
 *
 * @exponent: int, the power to raise a given number.
 *
 * Return: The final result of the calculation.
 */

int xToPowerY(int base, int exponent)
{
	int result = 1;
	int i;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}

	return (result);
}

/**
 * isBinaryNumber - Prints the elements of a linked list of integers.
 *
 * @str: A constant character pointing to string array.
 *
 *
 * Return: Returns 1 or 0.
 */

int isBinaryNumber(const char str[])
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1')
			return (0);
		i++;
	}

	return (1);
}

/**
 * binary_to_uint - converts binary number to usigned int.
 *
 * @b: A pointer to constant char.
 *
 * Return: Converts number to decimal.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int converted = 0;
	int num;
	int a;
	int len = 0;

	if (b == NULL)
		return (0);

	if (!isBinaryNumber(b))
		return (0);

	while (b[len] != '\0')
	{
		len++;
	}

	for (a = 0; a < len; a++)
	{
		int idx = len - (a + 1);

		num = b[idx];

		if (num == '1')
		{
			int current = xToPowerY(2, a);

			converted += current;
		}
	}

	return (converted);
}
