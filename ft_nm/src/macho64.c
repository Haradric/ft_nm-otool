
#include <mach-o/loader.h> // LC_SYMTAB symtab_command
#include <mach-o/nlist.h>  // nist_64

#include <stdlib.h>        // malloc()
#include <stdio.h> 	       // printf()

#include "nm.h"

static void	print_symtab_64(symtab_t *tab, size_t size) {

	size_t	i;

	i = 0;
	while (i < size) {
		printf("%s %d %d %d %llu\n", tab->n_name, tab->n_type, tab->n_sect, tab->n_desc, tab->n_value);
		tab = (void *)tab + sizeof(*tab);
		i++;
	}
}

static void	read_symtab_64(struct symtab_command *symcmd, symtab_t *tab, \
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

static void	*read_symtab_cmd_64(uint32_t ncmds, uint32_t lcoff, void *ptr) {

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

int			nm_macho64(void *ptr) {

	struct mach_header_64	*header;
	struct symtab_command   *symcmd;
	symtab_t				*symtab = NULL;

	header = (struct mach_header_64 *)ptr;
	symcmd = read_symtab_cmd_64(header->ncmds, sizeof(*header), ptr);

	symtab = malloc(sizeof(symtab_t) * symcmd->nsyms);
	read_symtab_64(symcmd, symtab, ptr);
	sort_symtab(symtab, symcmd->nsyms);
	print_symtab_64(symtab, symcmd->nsyms);
	free(symtab);

	return (0);
}
