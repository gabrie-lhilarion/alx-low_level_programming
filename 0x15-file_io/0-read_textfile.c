#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - read textfiles and return number of characters
 *
 * @filename: the file to be read
 *
 * @letters: number of letters
 *
 * Return: Total number of letter or 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor = open(filename, O_RDONLY);
	char *buffer = malloc(letters);
	ssize_t bytes_read = read(file_descriptor, buffer, letters);
	ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (filename == NULL)
		return (0);

	if (file_descriptor == -1)
		return (0);

	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	if (bytes_written != bytes_read)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	close(file_descriptor);

	free(buffer);

	return (bytes_written);
}
