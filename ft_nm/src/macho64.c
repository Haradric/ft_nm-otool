/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:01 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:01 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>

#include "ft_nm.h"

static void	read_symtab(struct symtab_command *symcmd, symtab_t *tab, void *ptr) {

    struct nlist_64 *symtab;
    uint8_t         *strtab;
    uint32_t        i;

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
        i++;
    }
}

static void	*get_symtab_lc(void *ptr) {

    struct load_command *lc;
    uint32_t ncmds;
    uint32_t i;

    lc = ptr + sizeof(struct mach_header_64);
    ncmds = ((struct mach_header_64 *)ptr)->ncmds;

    i = 0;
    while (i < ncmds) {
        if (lc->cmd == LC_SYMTAB)
            return (lc);
        lc = (void *)lc + lc->cmdsize;
        i++;
    }

    return (NULL);
}

int read_symtab_macho64(void *ptr, symtab_t **symtab, uint32_t *size) {

    struct symtab_command *symtab_lc;

    *symtab = NULL;
    symtab_lc = get_symtab_lc(ptr);

    *symtab = malloc(sizeof(symtab_t) * symtab_lc->nsyms);
    if (symtab == NULL)
        return (1);

    read_symtab(symtab_lc, *symtab, ptr);
    *size = symtab_lc->nsyms;

    sort_symtab(*symtab, *size);

    return (0);
}
