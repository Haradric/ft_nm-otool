
#include "ft_otool.h"

int     otool_read_file(const char *file, const char *sub, void *ptr, size_t size) {

    uint32_t    magic_number;
    int         ret = 0;

    magic_number = *(uint32_t *)ptr;

    if (magic_number == MH_MAGIC || magic_number == MH_CIGAM) {
        ret = handle_macho32(file, sub, ptr);
	} else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64) {
        ret = handle_macho64(file, sub, ptr);
    } else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM) {
        ret = handle_fat(file, ptr);
    } else if (magic_number == AR_MAGIC) {
        ret = handle_ar(file, ptr, size);
    } else {
        error_custom("otool", file, "not a valid object file");
        return (1);
    }

    return (ret);
}
