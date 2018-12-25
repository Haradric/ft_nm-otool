
#include <mach-o/loader.h> // LC_SYMTAB symtab_command
#include <mach-o/nlist.h>  // nist_64
#include <stddef.h>        // size_t
#include <stdio.h>         // printf()

#include "libft.h"
#include "nm.h"

static char get_type(symtab_t *tab) {

    index_t *index;
    char    ret;
    uint8_t type;
    uint8_t external;

    type = tab->n_type & N_TYPE;
    external  = tab->n_type & N_EXT;
    index = get_sect_index();
    if ((tab->n_type & N_TYPE) == N_UNDF)
        ret = 'U';
    else if (type == N_ABS)
        ret = (external) ? 'A' : 'a';
    else if (type == N_INDR)
        ret = (external) ? 'I' : 'i';
    else if (type == N_SECT && tab->n_sect == index->text)
        ret = (external) ? 'T' : 't';
    else if (type == N_SECT && tab->n_sect == index->data)
        ret = (external) ? 'D' : 'd';
    else if (type == N_SECT && tab->n_sect == index->bss)
        ret = (external) ? 'B' : 'b';
    else
        ret = (external) ? 'S' : 's';

    return (ret);
}

void        print_symtab(symtab_t *tab, size_t size, int width) {

    uint8_t type;
    uint8_t ext;
    size_t  i;

    i = 0;
    while (i < size) {
        type = tab->n_type & N_TYPE;
        ext  = tab->n_type & N_EXT;
        if ((tab->n_type & N_TYPE) == N_UNDF)
            ft_printf("%*c %c %s\n", width, ' ', get_type(tab), tab->n_name);
        else
            ft_printf("%0*x %c %s\n", width, (unsigned)tab->n_value, get_type(tab), tab->n_name);
        tab = (void *)tab + sizeof(*tab);
        i++;
    }
}
