
#include <mach-o/fat.h>    // FAT_MAGIC*, FAT_CIGAM*

#include "nm.h"

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
        nm_read_file(name, NULL, ptr + big_to_little_uint32(arch[i].offset), 0);
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
            nm_read_file(name, NULL, ptr + big_to_little_uint32(arch[i].offset), 0);
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
