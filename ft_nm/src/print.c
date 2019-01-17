
#include <unistd.h>
#include <mach-o/nlist.h>

#include "ft_nm.h"

void print_filename_arch(const char *name, uint32_t cpu) {

    if (cpu == CPU_TYPE_POWERPC)
        print_filename(name, "ppc");
    else if (cpu == CPU_TYPE_POWERPC64)
        print_filename(name, "ppc64");
    else if (cpu == CPU_TYPE_I386)
        print_filename(name, "i386");
    else if (cpu == CPU_TYPE_X86_64)
        print_filename(name, "x86_64");
}

void print_filename(const char *name, const char *sub) {

    if (name) {
        write(STDOUT_FILENO, "\n", 1);
        write(STDOUT_FILENO, name, ft_strlen(name));
        if (sub) {
            write(STDOUT_FILENO, "(", 1);
            write(STDOUT_FILENO, sub, ft_strlen(sub));
            write(STDOUT_FILENO, ")", 1);
        }
        write(STDOUT_FILENO, ":\n", 2);
    }
}

static char *uint64_to_hex(uint64_t n, size_t len) {

    static char buff[17] = {0};
    const char  *hex = "0123456789abcdef";
    size_t      i;

    buff[len] = 0;
    i = len - 1;
    while (i < 16) {
        buff[i] = hex[n % 16];
        n /= 16;
        i--;
    }

    return ((char *)&buff);
}

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
    size_t  i;

    i = 0;
    while (i < size) {
        type = tab->n_type & N_TYPE;
        if (type == N_UNDF)
            ft_printf("%*c %c %s\n", width, ' ', get_type(tab), tab->n_name);
        else if (type == N_INDR)
            ft_printf("%*c %c %s (indirect for %s)\n", width, ' ', get_type(tab), tab->n_name, tab->n_name);
        else
            ft_printf("%s %c %s\n", uint64_to_hex(tab->n_value, width), get_type(tab), tab->n_name);
        tab = (void *)tab + sizeof(*tab);
        i++;
    }
}
