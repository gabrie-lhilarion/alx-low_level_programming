#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * total_chars - get the total count of characters
 *
 * @str: the string to count
 *
 * Return: total numberf of characters
 */

size_t total_chars(const char *str)
{
	size_t count = 0;

	while (str[count] != '\0')
	{
		count++;
	}

	return (count);
}


/**
 * append_text_to_file - read textfiles and return number of characters
 *
 * @filename: the file to be read
 *
 * @text_content: number of letters
 *
 * Return: 1 or -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	size_t content_length = total_chars(text_content);
	int file_descriptor = open(filename, O_WRONLY | O_APPEND);
	ssize_t bytes_written = write(file_descriptor, text_content, content_length);

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	if (file_descriptor == -1)
		return (-1);

	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);

	return (1);
}
