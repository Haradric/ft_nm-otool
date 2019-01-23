
#ifndef FT_OTOOL_H
#define FT_OTOOL_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ar.h>
#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <mach-o/ranlib.h>

#include "libft.h"

#define AR_MAGIC 0x72613c21  /* magic string in uint32_t */

#define HOSTARCH ((sizeof(void *) == 4) ? CPU_TYPE_I386 : CPU_TYPE_X86_64)

typedef struct  otool_obj {
    struct stat st;
    void        *ptr;
    int         fd;
}               otool_obj_t;

int     otool_read_file(const char *path, void *ptr, size_t size);

int     handle_macho32(const char *name, void *ptr);
int     handle_macho64(const char *name, void *ptr);
int     handle_fat(const char *name, void *ptr);
int     handle_ar(const char *name, void *ptr, size_t size);

void    get_text_sect32(void *ptr);
void    get_text_sect64(void *ptr);
int     read_fat(const char *name, void *ptr);

void    print_filename(const char *name, const char *sub, uint32_t arch);

void    error(const char *prefix, const char *str);
void    error_custom(const char *prefix, const char *str, const char *err);
void    terminate(const char *prefix, const char *str);
void    terminate_custom(const char *prefix, const char *str, const char *err);

uint32_t big_to_little_uint32(uint32_t x);
uint64_t big_to_little_uint64(uint64_t x);
char     *uint8_hex_str(uint8_t n);
char     *uint32_hex_str(uint32_t n);
char     *uint64_hex_str(uint64_t n);

#endif /* FT_OTOOL_H */
