
#include "ft_otool.h"

static int fat_check_own(struct fat_arch *arch, size_t n) {

    uint32_t i;

    i = 0;
    while (i < n) {
        if (btlu32(arch[i].cputype) == HOSTARCH)
            return (1);
        i++;
    }

    return (0);
}

int read_fat(const char *name, void *ptr) {

    struct fat_header *header;
    struct fat_arch   *arch;
    int      own;
    uint32_t n;
    uint32_t i;

    header = ptr;
    arch = ptr + sizeof(*header);
    n = btlu32(header->nfat_arch);
    own = fat_check_own(arch, n);

    i = -1;
    while (++i < n) {
        if (own && btlu32(arch[i].cputype) != HOSTARCH)
            continue ;
        otool_read_file(name, ptr + btlu32(arch[i].offset), btlu32(arch[i].size));
    }

    return (0);
}
