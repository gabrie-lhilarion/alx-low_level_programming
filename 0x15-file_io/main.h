#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#define ELF_MAGIC_SIZE 4

int _putchar(char c);

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

int append_text_to_file(const char *filename, char *text_content);

size_t total_chars(const char *str);

typedef struct
{
        unsigned char e_ident[ELF_MAGIC_SIZE];
        uint8_t e_class;
        uint8_t e_data;
        uint8_t e_version;
        uint8_t e_osabi;
        uint8_t e_abiver;
        uint8_t e_pad[7];
        uint16_t e_type;
        uint16_t e_machine;
        uint32_t e_version2;
        uint64_t e_entry;
} ElfHeader;

#endif