#include <stdio.h>

int xToPowerY(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int isBinaryNumber(const char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            return 0; // Not a valid binary number
        }
    }
    return 1; // It's a valid binary number
}

unsigned int binary_to_uint(const char *b)
{
    if (!isBinaryNumber(b))
    {
        printf("Invalid binary input\n");
        return 0;
    }

    unsigned int converted = 0;
    int len = 0;

    // Calculate the length of the string manually
    while (b[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len; i++)
    {
        int idx = len - (i + 1);
        int num = b[i] - '0'; // Convert character '0' or '1' to integer 0 or 1

        if (num == 1)
        {
            int current = xToPowerY(2, i);
            converted += current;
        }
    }

    printf("Converted: %u\n", converted);

    return converted;
}

int main()
{
    unsigned int result = binary_to_uint("1e01");
    printf("Result: %u\n", result);

    return 0;
}
