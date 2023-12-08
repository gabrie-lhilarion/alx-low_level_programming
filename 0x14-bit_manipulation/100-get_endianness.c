/**
 * get_endianness - The get endianness of system
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int num = 1;

	if (*(char *)&num == 1)
		return (1);
	else
		return (0);
}
