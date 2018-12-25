
#include <mach-o/loader.h> // LC_SYMTAB symtab_command
#include <mach-o/nlist.h>  // struct nlist_64
#include <stdlib.h>        // malloc()

#include "libft.h"         // ft_strcmp()
#include "nm.h"

static void read_segment_64(struct load_command *lc) {

    struct segment_command_64 *segment;
    struct section_64         *section;
    index_t                   *index;
    size_t                    i;

    segment = (struct segment_command_64 *)lc;
    section = (struct section_64 *)((void*)segment + sizeof(*segment));
    index = get_sect_index();

    i = 0;
    while (i < segment->nsects) {
        if (!ft_strcmp(section->segname, SEG_TEXT) && !ft_strcmp(section->sectname, SECT_TEXT))
            index->text = index->nsects + 1;
        else if (!ft_strcmp(section->segname, SEG_DATA) && !ft_strcmp(section->sectname, SECT_DATA))
            index->data = index->nsects + 1;
        else if (!ft_strcmp(section->segname, SEG_DATA) && !ft_strcmp(section->sectname, SECT_BSS))
            index->bss = index->nsects + 1;
        index->nsects++;
        section++;
        i++;
    }
}

static void	read_symtab_64(struct symtab_command *symcmd, symtab_t *tab, void *ptr) {

    struct nlist_64 *symtab;
    uint8_t         *strtab;
    size_t          i;

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

static void	*read_load_commands_64(struct mach_header_64 *header, void *ptr) {

    struct load_command *lc;
    size_t              i;
    void                *symcmd;

    ft_memset(get_sect_index(), 0, sizeof(index_t));
    lc = ptr + sizeof(*header);
    symcmd = NULL;
    i = 0;
    while (i < header->ncmds) {
        if (lc->cmd == LC_SEGMENT_64) {
            read_segment_64(lc);
        }
        else if (lc->cmd == LC_SYMTAB) {
            symcmd = lc;
        }
        lc = (void *)lc + lc->cmdsize;
        ++i;
    }

    return (symcmd);
}

int     nm_macho64(void *ptr) {

    struct mach_header_64 *header;
    struct symtab_command *symcmd;
    symtab_t              *symtab;

    header = (struct mach_header_64 *)ptr;
    symcmd = read_load_commands_64(header, ptr);

    symtab = malloc(sizeof(symtab_t) * symcmd->nsyms);
    read_symtab_64(symcmd, symtab, ptr);
    sort_symtab(symtab, symcmd->nsyms);
    print_symtab(symtab, symcmd->nsyms, 16);
    free(symtab);

    return (0);
}
