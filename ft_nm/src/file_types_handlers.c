
#include <mach-o/loader.h> // MH_MAGIC_*, MH_CIGAM_*
//#include <mach-o/stab.h>
#include <mach-o/fat.h>    // FAT_MAGIC*, FAT_CIGAM*
#include <stdio.h>         // printf()
#include <stdlib.h>        // free()

#include "nm.h"

int handle_macho32(void *ptr) {

    symtab_t *symtab = NULL;
    uint32_t symtab_size;

//    printf("mach-o 32-bit\n");
//    set endianness
    index_sections(((struct mach_header *)ptr)->ncmds, ptr + sizeof(struct mach_header));
    if (!read_symtab_macho32(ptr, &symtab, &symtab_size)) {
        print_symtab(symtab, symtab_size, 8);
        free(symtab);
        return (0);
    }

    return (1);
}

int handle_macho64(void *ptr) {

    symtab_t *symtab = NULL;
    uint32_t symtab_size;

//    printf("mach-o 64-bit\n");
//    set endianness
    index_sections(((struct mach_header_64 *)ptr)->ncmds, ptr + sizeof(struct mach_header_64));
    if (!read_symtab_macho64(ptr, &symtab, &symtab_size)) {
        print_symtab(symtab, symtab_size, 16);
        free(symtab);
        return (0);
    }

    return (1);
}

int handle_fat32(void *ptr) {

    (void)ptr;
    printf("not implemented - universal (fat) binary 32-bit\n");

    return (1);
}

int handle_fat64(void *ptr) {

    (void)ptr;
    printf("not implemented - universal (fat) binary 64-bit\n");

    return (1);
}

int handle_ar(void *ptr) {

    (void)ptr;
    printf("not implemented - ar archive\n");

    return (1);
}
