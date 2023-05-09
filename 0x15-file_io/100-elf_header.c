#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void error_exit(char *message);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident[EI_NIDENT]);
void print_data(unsigned char e_ident[EI_NIDENT]);
void print_version(unsigned char e_ident[EI_NIDENT]);
void print_osabi(unsigned char e_ident[EI_NIDENT]);
void print_abiversion(unsigned char e_ident[EI_NIDENT]);
void print_type(Elf64_Half e_type);
void print_entry(Elf64_Addr e_entry);

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename\n");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open file\n");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit("Error: Cannot read file header\n");

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1
			|| header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file\n");

	printf("Magic:   ");
	print_magic(header.e_ident);

	printf("Class:                             ");
	print_class(header.e_ident);

	printf("Data:                              ");
	print_data(header.e_ident);

	printf("Version:                           ");
	print_version(header.e_ident);

	printf("OS/ABI:                            ");
	print_osabi(header.e_ident);

	printf("ABI Version:                       ");
	print_abiversion(header.e_ident);

	printf("Type:                              ");
	print_type(header.e_type);

	printf("Entry point address:               ");
	print_entry(header.e_entry);

	close(fd);
	return (0);
}

/**
 * error_exit - prints an error message to stderr and exits with status code 98
 * @message: the error message to print
 */
void error_exit(char *message)
{
	fprintf(stderr, "%s", message);
	exit(98);
}

/**
 * print_magic - prints the magic number in the ELF header
 * @e_ident: the ELF identification bytes in the header
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * print_class - prints the class of the ELF header
 * @e_ident: the ELF identification bytes in the header
 */
void print_class(unsigned char e_ident[EI_NIDENT])
{
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - prints the byte order of the ELF header
 * @e_ident: the ELF identification bytes in the header
 */

void print_data(unsigned char e_ident[EI_NIDENT])
{
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			break;
	}
}
/**
 * print_version - prints the version of the ELF header
 * @e_ident: the ELF identification bytes in the header
 */
void print_version(unsigned char e_ident[EI_NIDENT])
{
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("none\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_VERSION]);
			break;
	}
}

/**
 * print_osabi - prints the OS/ABI of the ELF header
 * @e_ident: the ELF identification bytes in the header
 */
void print_osabi(unsigned char e_ident[EI_NIDENT])
{
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("UNIX - ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone Applicatoin\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - prints the ABI version of the ELF header
 * @e_ident: the ELF identification bytes in the header
 */
void print_abiversion(unsigned char e_ident[EI_NIDENT])
{
	printf("%d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of the ELF header
 * @e_type: the e_type field in the ELF header
 */
void print_type(Elf64_Half e_type)
{
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			break;
	}
}

/**
 * print_entry - prints the entry point address of the ELF header
 * @e_entry: the e_entry field in the ELF header
 */
void print_entry(Elf64_Addr e_entry)
{
	printf("0x%lx\n", e_entry);
}

