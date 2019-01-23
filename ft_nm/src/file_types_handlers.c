
#include "ft_nm.h"

int handle_macho32(const char *name, void *ptr) {

    symtab_t *symtab = NULL;
    uint32_t symtab_size;

//    printf("mach-o 32-bit\n");
//    set endianness
    index_sections(((struct mach_header *)ptr)->ncmds, ptr + sizeof(struct mach_header));
    if (!read_symtab_macho32(ptr, &symtab, &symtab_size)) {
        print_filename(name, ((struct mach_header *)ptr)->cputype);
        print_symtab(symtab, symtab_size, 8);
        free(symtab);
        return (0);
    }

    return (1);
}

int handle_macho64(const char *name, void *ptr) {

    symtab_t *symtab = NULL;
    uint32_t symtab_size;

//    printf("mach-o 64-bit\n");
//    set endianness
    index_sections(((struct mach_header_64 *)ptr)->ncmds, ptr + sizeof(struct mach_header_64));
    if (!read_symtab_macho64(ptr, &symtab, &symtab_size)) {
        print_filename(name, ((struct mach_header_64 *)ptr)->cputype);
        print_symtab(symtab, symtab_size, 16);
        free(symtab);
        return (0);
    }

    return (1);
}

int handle_fat(const char *name, void *ptr, int multifile) {

    return (read_fat(name, ptr, multifile));
}

int handle_ar(const char *name, void *ptr, size_t size) {

    struct ar_hdr *header;
    char *str;
    char *tmp;
    void *end;
    void *file;

    end = ptr + size;
    header = ptr + SARMAG;
    ptr = (void *)header + sizeof(*header) + ft_atoi(header->ar_size);

    while (ptr < end) {
        header = ptr;
        str = (void *)header + sizeof(*header);
        file = str + ft_strlen(str);
        while (!*(char *)file)
            file++;
        tmp = genname((char *)name, str);
        nm_read_file(tmp, file, ft_atoi(header->ar_size), 1);
        free(tmp);
        ptr += sizeof(*header) + ft_atoi(header->ar_size);
    }

    return (0);
}
