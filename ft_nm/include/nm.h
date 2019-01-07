
#ifndef NM_H
#define NM_H

#include <stdint.h>
#include <stddef.h>

#define AR_MAGIC 0x72613c21

typedef struct  symtab {
    uint8_t     *n_name;
    uint8_t     n_type;
    uint8_t     n_sect;
    uint16_t    n_desc;
    uint64_t    n_value;
}               symtab_t;

typedef struct  section_index {
    uint8_t     nsects;
    uint8_t     text;
    uint8_t     data;
    uint8_t     bss;
}               index_t;

index_t *get_sect_index(void);

int     nm_read_file(const char *path, void *ptr);

int     handle_macho32(void *ptr);
int     handle_macho64(void *ptr);
int     handle_fat32(void *ptr);
int     handle_fat64(void *ptr);
int     handle_ar(void *ptr);

int     nm_macho32(void *ptr);
int     nm_macho64(void *ptr);

void    index_sections(uint32_t ncmds, void *lc_start);
index_t *get_sect_index(void);

void    sort_symtab(struct symtab *arr, size_t n);

void    print_symtab(symtab_t *tab, size_t size, int addr_size);

void    error(const char *prefix, const char *str);
void    error_custom(const char *prefix, const char *str, const char *err);
void    terminate(const char *prefix, const char *str);
void    terminate_custom(const char *prefix, const char *str, const char *err);

#endif /* NM_H */
