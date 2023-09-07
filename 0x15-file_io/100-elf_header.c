#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define ELF_MAGIC_SIZE 4
#define ELF_HEADER_SIZE 52

typedef struct {
    unsigned char e_ident[ELF_MAGIC_SIZE];
    uint8_t e_class;
    uint8_t e_data;
    uint8_t e_version;
    uint8_t e_osabi;
    uint8_t e_abiversion;
    uint8_t e_padding[7];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version2;
    uint64_t e_entry;
} ElfHeader;

void print_elf_header(ElfHeader *header) {
    printf("Magic:   ");
    for (int i = 0; i < ELF_MAGIC_SIZE; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    
    printf("Class:                             %s\n",
           header->e_class == 1 ? "ELF32" : "ELF64");
    
    printf("Data:                              %s\n",
           header->e_data == 1 ? "2's complement, little endian" : "2's complement, big endian");
    
    printf("Version:                           %d (current)\n", header->e_version);
    
    printf("OS/ABI:                            %d\n", header->e_osabi);
    
    printf("ABI Version:                       %d\n", header->e_abiversion);
    
    printf("Type:                              0x%x\n", header->e_type);
    
    printf("Entry point address:               0x%llx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(98);
    }

    ElfHeader header;
    ssize_t bytes_read = read(fd, &header, ELF_HEADER_SIZE);

    if (bytes_read != ELF_HEADER_SIZE ||
        strncmp((char *)header.e_ident, "\x7f""ELF", ELF_MAGIC_SIZE) != 0) {
        fprintf(stderr, "%s is not an ELF file\n", filename);
        close(fd);
        exit(98);
    }

    print_elf_header(&header);
    close(fd);

    return 0;
}
