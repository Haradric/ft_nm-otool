
#include <mach-o/loader.h> // LC_SYMTAB symtab_command
#include <mach-o/nlist.h>  // struct nlist
#include <stdlib.h>        // malloc()

#include "nm.h"

static void read_symtab(struct symtab_command *symcmd, symtab_t *tab, void *ptr) {

    struct nlist *symtab;
    uint8_t      *strtab;
    uint32_t     i;

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

static void *get_symtab_lc(void *ptr) {

    struct load_command *lc;
    uint32_t ncmds;
    uint32_t i;

    lc = ptr + sizeof(struct mach_header);

    ncmds = ((struct mach_header *)ptr)->ncmds;
    i = 0;
    while (i < ncmds) {
        if (lc->cmd == LC_SYMTAB)
            return (lc);
        lc = (void *)lc + lc->cmdsize;
        ++i;
    }

    return (NULL); // need to be handled
}

int nm_macho32(void *ptr) {

    struct symtab_command *symtab_lc;
    symtab_t              *symtab;

    symtab_lc = get_symtab_lc(ptr);

    symtab = malloc(sizeof(symtab_t) * symtab_lc->nsyms);
    read_symtab(symtab_lc, symtab, ptr);
    sort_symtab(symtab, symtab_lc->nsyms);
    print_symtab(symtab, symtab_lc->nsyms, 8);
    free(symtab);

    return (0);
}
