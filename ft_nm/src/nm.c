
#include <mach-o/loader.h> // MH_MAGIC_*, MH_CIGAM_*
//#include <mach-o/stab.h>
#include <mach-o/fat.h>    // FAT_MAGIC*, FAT_CIGAM*
#include <ar.h>

#include "nm.h"

int     nm_read_file(const char *file, void *ptr, int multifile) {

    uint32_t    magic_number;
    int         ret = 0;

    magic_number = *(uint32_t *)ptr;

    if (magic_number == MH_MAGIC || magic_number == MH_CIGAM) {
        ret = handle_macho32(multifile ? file : NULL, ptr);
	} else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64) {
        ret = handle_macho64(multifile ? file : NULL, ptr);
    } else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM) {
        ret = handle_fat32(multifile ? file : NULL, ptr);
    } else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64) {
        ret = handle_fat64(multifile ? file : NULL, ptr);
    } else if (magic_number == AR_MAGIC) {
        ret = handle_ar(multifile ? file : NULL, ptr);
    } else {
        error_custom("nm", file, "not a valid object file");
        return (1);
    }

    return (ret);
}
