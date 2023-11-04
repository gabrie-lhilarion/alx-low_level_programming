#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include "main.h"

#define ELF_MAGIC_SIZE 4
#define ELF_HEADER_SIZE 52

/**
 * error - prints the error message
 *
 * @msg: the error massage
 */

void error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * read_elf_header - reads elf header of a file
 *
 * @filename: the file name
 *
 * Return: void
 */

void read_elf_header(const char *filename)
{
	ElfHeader header;

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		error("Error: Cannot open file");
	}


	if (read(fd, &header, ELF_HEADER_SIZE) != ELF_HEADER_SIZE)
	{
		close(fd);
		error("Error: Cannot read ELF header");
	}

	if (strncmp((char *)header.e_ident, "\x7F" "ELF", ELF_MAGIC_SIZE) != 0)
	{
		close(fd);
		error("Error: Not an ELF file");
	}

	printf("  Magic:   %02X %02X %02X %02X\n", header.e_ident[0], header.e_ident[1], header.e_ident[2], header.e_ident[3]);
	printf("  Class:                             %d-bit\n", header.e_class == 1 ? 32 : (header.e_class == 2 ? 64 : 0));
	printf("  Data:                              %s\n", header.e_data == 1 ? "2's complement, little endian" : (header.e_data == 2 ? "2's complement, big endian" : "Unknown"));
	printf("  Version:                           %d\n", header.e_version);
	printf("  OS/ABI:                            %d\n", header.e_osabi);
	printf("  ABI Version:                       %d\n", header.e_abiver);
	printf("  Type:                              0x%04X\n", header.e_type);
	printf("  Entry point address:               0x%08lX\n", header.e_entry);
	close(fd);
}


int main(int argc, char *argv[]) {
	const char *filename = argv[1];

	if (argc != 2) {
		error("Usage: elf_header elf_filename");
	}

	read_elf_header(filename);
	return 0;
}
