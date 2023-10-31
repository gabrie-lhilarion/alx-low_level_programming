#include <sys/types.h>

size_t total_chars(const char *str)
{
    size_t count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
