
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
//#include <mach-o/stab.h>
#include <mach-o/fat.h>

#include <stdlib.h> // malloc()
#include <stdio.h> 	// printf()

#include "libft.h"
#include "nm.h"

void	print_symtab_64(symtab_t *tab, size_t size) {

	size_t	i;

	i = 0;
	while (i < size) {
		printf("%s\n", tab->n_name);
		tab = (void *)tab + sizeof(*tab);
		i++;
	}
}

void 	read_symtab_64(struct symtab_command *symcmd, symtab_t *tab, \
					   void *ptr) {

	struct nlist_64 *symtab;
	uint8_t 		*strtab;
	size_t			i;

	symtab = ptr + symcmd->symoff;
	strtab = ptr + symcmd->stroff;
	i = 0;
	while (i < symcmd->nsyms) {
		tab->n_name = strtab + symtab[i].n_un.n_strx;
		tab->n_type = symtab[i].n_type;
		tab->n_sect = symtab[i].n_sect;
		tab->n_desc = symtab[i].n_desc;
		tab->n_value = symtab[i].n_value;
		tab = (void *)tab + sizeof(*tab);
		++i;
	}
}

void	*read_symtab_cmd_64(uint32_t ncmds, uint32_t lcoff, void *ptr) {

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
	symtab_t				*symtab = NULL;

    header = (struct mach_header_64 *)ptr;
	symcmd = read_symtab_cmd_64(header->ncmds, sizeof(*header), ptr);

	symtab = malloc(sizeof(symtab_t) * symcmd->nsyms);
	read_symtab_64(symcmd, symtab, ptr);
	sort_symtab(symtab, symcmd->nsyms);
	print_symtab_64(symtab, symcmd->nsyms);
//	free symtab

	return (0);
}

int		read_mach_o(const char *file, void *ptr) {
    
    uint32_t	magic_number;
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
