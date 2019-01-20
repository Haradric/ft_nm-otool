
#include "ft_otool.h"

static int fat_read_all(const char *name, void *ptr) {

    struct fat_header *header;
    struct fat_arch   *arch;
    uint32_t n;
    uint32_t i;

    header = ptr;
    arch = ptr + sizeof(*header);
    n = big_to_little_uint32(header->nfat_arch);

    i = 0;
    while (i < n) {
        print_filename_arch(name, big_to_little_uint32(arch[i].cputype));
        otool_read_file(NULL, NULL, ptr + big_to_little_uint32(arch[i].offset), big_to_little_uint32(arch[i].size));
        i++;
    }

    return (0);
}

static int fat_read_one(const char *name, void *ptr) {

    struct fat_header *header;
    struct fat_arch   *arch;
    uint32_t n;
    uint32_t i;

    header = ptr;
    arch = ptr + sizeof(*header);
    n = big_to_little_uint32(header->nfat_arch);

    i = 0;
    while (i < n) {
        if (big_to_little_uint32(arch[i].cputype) == HOSTARCH) {
            print_filename_arch(name, big_to_little_uint32(arch[i].cputype));
            otool_read_file(NULL, NULL, ptr + big_to_little_uint32(arch[i].offset), big_to_little_uint32(arch[i].size));
            return (0);
        }
        i++;
    }

    return (1);
}

static int fat_check_own(void *ptr) {

    struct fat_header *header;
    struct fat_arch   *arch;
    uint32_t n;
    uint32_t i;

    header = ptr;
    arch = ptr + sizeof(*header);
    n = big_to_little_uint32(header->nfat_arch);

    i = 0;
    while (i < n) {
        if (big_to_little_uint32(arch[i].cputype) == HOSTARCH)
            return (1);
        i++;
    }

    return (1);
}

int read_fat(const char *name, void *ptr) {

    if (fat_check_own(ptr))
        return (fat_read_one(name, ptr));
    else
        return (fat_read_all(name, ptr));
}
