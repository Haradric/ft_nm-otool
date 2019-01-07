
#include <mach-o/loader.h> // MH_MAGIC_*, MH_CIGAM_*
//#include <mach-o/stab.h>
#include <mach-o/fat.h>    // FAT_MAGIC*, FAT_CIGAM*
#include <stdio.h>         // printf()

#include "nm.h"

int handle_macho32(void *ptr) {

    int ret = 0;

//    printf("mach-o 32-bit\n");
//    set endianness
    index_sections(((struct mach_header *)ptr)->ncmds, ptr + sizeof(struct mach_header));
    ret = nm_macho32(ptr);

    return (ret);
}

int handle_macho64(void *ptr) {

    int ret = 0;

//    printf("mach-o 64-bit\n");
//    set endianness
    index_sections(((struct mach_header_64 *)ptr)->ncmds, ptr + sizeof(struct mach_header_64));
    ret = nm_macho64(ptr);

    return (ret);
}

int handle_fat32(void *ptr) {

    (void)ptr;
    printf("not implemented - universal (fat) binary\n");

    return (1);
}

int handle_fat64(void *ptr) {

    (void)ptr;
    printf("not implemented - fat 64-bit\n");

    return (1);
}

int handle_ar(void *ptr) {

    (void)ptr;
    printf("not implemented - ar archive\n");

    return (1);
}
