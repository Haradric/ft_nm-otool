
#include <mach-o/loader.h> // MH_MAGIC_*, MH_CIGAM_*
//#include <mach-o/stab.h>
#include <mach-o/fat.h>    // FAT_MAGIC*, FAT_CIGAM*
#include <mach-o/ranlib.h> //
#include <ar.h>
#include <stdlib.h>        // free()

#include "nm.h"

int handle_macho32(const char *name, const char *sub, void *ptr) {

    symtab_t *symtab = NULL;
    uint32_t symtab_size;

//    printf("mach-o 32-bit\n");
//    set endianness
    index_sections(((struct mach_header *)ptr)->ncmds, ptr + sizeof(struct mach_header));
    if (!read_symtab_macho32(ptr, &symtab, &symtab_size)) {
        print_filename(name, sub);
        print_symtab(symtab, symtab_size, 8);
        free(symtab);
        return (0);
    }

    return (1);
}

int handle_macho64(const char *name, const char *sub, void *ptr) {

    symtab_t *symtab = NULL;
    uint32_t symtab_size;

//    printf("mach-o 64-bit\n");
//    set endianness
    index_sections(((struct mach_header_64 *)ptr)->ncmds, ptr + sizeof(struct mach_header_64));
    if (!read_symtab_macho64(ptr, &symtab, &symtab_size)) {
        print_filename(name, sub);
        print_symtab(symtab, symtab_size, 16);
        free(symtab);
        return (0);
    }

    return (1);
}

int handle_fat(const char *name, void *ptr) {

    return (read_fat(name, ptr));
}

int handle_ar(const char *name, void *ptr, size_t size) {

    struct ar_hdr *header;
    char          *str;
    void *end;
    void *file;

    end = ptr + size;
    header = ptr + SARMAG;
    ptr = (void *)header + sizeof(*header) + atoi(header->ar_size);

    while (ptr < end) {
        header = ptr;
        str = (void *)header + sizeof(*header);
        file = str;
        while (*(char *)file)
            file++;
        while (!*(char *)file)
            file++;
        print_filename(name, str);
        nm_read_file(NULL, NULL, file, atoi(header->ar_size));
        ptr += sizeof(*header) + atoi(header->ar_size);
    }

    return (0);
}
