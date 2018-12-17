
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <stdio.h> // printf()

#include "nm.h"

void	print_symtab_64(uint32_t nsyms, uint32_t symoff, uint32_t stroff, \
						void *ptr) {

	struct nlist_64 *symtab;
	char 			*strtab;
	size_t			i;

	symtab = ptr + symoff;
	strtab = ptr + stroff;
	i = 0;
	while (i < nsyms) {
		printf("%s\n", strtab + symtab[i].n_un.n_strx);
		++i;
	}
}

void	*get_symtab_command_64(uint32_t ncmds, uint32_t lcoff, void *ptr) {

	struct load_command	*lc;
	size_t				i;

	lc = ptr + lcoff;
	i = 0;
	while (i < ncmds) {
		if (lc->cmd == LC_SYMTAB) {
			return (lc);
		}
		lc = (void *)lc + lc->cmdsize;
		++i;
	}
	return (NULL);
}

int		handle_64(void *ptr) {

    struct mach_header_64	*header;
	struct symtab_command   *symcmd;

    header = (struct mach_header_64 *)ptr;
	symcmd = get_symtab_command_64(header->ncmds, sizeof(*header), ptr);
	print_symtab_64(symcmd->nsyms, symcmd->symoff, symcmd->stroff, ptr);

	return (0);
}

int             read_mach_o(const char *file, void *ptr) {
    
    uint32_t    magic_number;
    int         ret = 0;

    magic_number = *(uint32_t *)ptr;

	if (magic_number == MH_MAGIC || magic_number == MH_CIGAM) {
		printf("not implemented - mach-o 32-bit\n");
//		ret =  handle_32(ptr);
	} else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64) {
		ret = handle_64(ptr);
	} else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM) {
		printf("not implemented - fat 32-bit\n");
	} else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64) {
		printf("not implemented - fat 64-bit\n");
	} else {
		error_custom("nm", file, "not a valid object file");
		return (1);
	}

    return (ret);
}
