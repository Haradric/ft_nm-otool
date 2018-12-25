
#include <mach-o/loader.h> // MH_MAGIC_*, MH_CIGAM_*
//#include <mach-o/stab.h>
#include <mach-o/fat.h>    // FAT_MAGIC*, FAT_CIGAM*
#include <stdio.h> 	       // printf()

#include "nm.h"

index_t *get_sect_index(void) {
    static index_t index = {0};

    return (&index);
}

int     nm_read_file(const char *file, void *ptr) {

    uint32_t    magic_number;
    int         ret = 0;

    magic_number = *(uint32_t *)ptr;

    if (magic_number == MH_MAGIC || magic_number == MH_CIGAM) {
//        printf("mach-o 32-bit\n");
        ret =  nm_macho32(ptr);
	} else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64) {
//        printf("mach-o 64-bit\n");
        ret = nm_macho64(ptr);
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
