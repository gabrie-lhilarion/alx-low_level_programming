#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

/**
 * create_file - read textfiles and return number of characters
 *
 * @filename: the file to be created
 *
 * @text_content: content to be in file
 *
 * Return: 1 on success -1 on failure
 */


int create_file(const char *filename, char *text_content)
{
	int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (filename == NULL)
		return (-1);

	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		ssize_t written = write(file_descriptor, text_content, strlen(text_content));

		if (written == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);

	return (1);
}
