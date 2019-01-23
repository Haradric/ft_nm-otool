
#include "ft_otool.h"

int handle_macho32(const char *name, void *ptr) {

    //    printf("mach-o 64-bit\n");
    //    set endianness

    print_filename(name, ((struct mach_header *)ptr)->cputype);
    get_text_sect32(ptr);

    return (0);
}

int handle_macho64(const char *name, void *ptr) {

//    printf("mach-o 64-bit\n");
//    set endianness

    print_filename(name, ((struct mach_header_64 *)ptr)->cputype);
    get_text_sect64(ptr);

    return (0);
}

int handle_fat(const char *name, void *ptr) {

    return (read_fat(name, ptr));
}

int handle_ar(const char *name, void *ptr, size_t size) {

    struct ar_hdr *header;
    char *str;
    char *tmp;
    void *end;
    void *file;

    ft_printf("Archive : %s\n", name);
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
        otool_read_file(tmp, file, ft_atoi(header->ar_size));
        free(tmp);
        ptr += sizeof(*header) + ft_atoi(header->ar_size);
    }

    return (0);
}
