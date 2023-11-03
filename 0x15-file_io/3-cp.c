#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdarg.h>

#define BUF_SIZE 1024


/**
 * error - functionto handle exit error
 *
 * @exit_code: int representing the exit code
 *
 * @fmt: formated sting showing error
 *
 * Return: void
 */

void error(int exit_code, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	dprintf(2, fmt, args);
	va_end(args);

	exit(exit_code);
}

/**
 * main - program entry point
 *
 * @argc : argument count
 *
 * @argv: list of files
 *
 * Return: void
 */

int main(int argc, char *argv[])
{
	char buffer[BUF_SIZE];
	ssize_t bytes_read, bytes_written;
	int fd_src;
	int fd_dest;

	const char *file_from = argv[1];
	const char *file_to = argv[2];

	fd_src = open(file_from, O_RDONLY);
	umask(0);
	fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (argc != 3)
		error(97, "Usage: cp file_from file_to\n");

	if (fd_src == -1)
		error(98, "Error: Can't read from file %s\n", file_from);

	if (fd_dest == -1)
		error(99, "Error: Can't write to file %s\n", file_to);

	while ((bytes_read = read(fd_src, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_dest, buffer, bytes_read);

		if (bytes_written != bytes_read)
			error(99, "Error: Can't write to file %s\n", file_to);
	}

	if (bytes_read == -1)
		error(98, "Error: Can't read from file %s\n", file_from);

	if (close(fd_src) == -1)
		error(100, "Error: Can't close fd %d\n", fd_src);

	if (close(fd_dest) == -1)
		error(100, "Error: Can't close fd %d\n", fd_dest);

	return (0);
}

