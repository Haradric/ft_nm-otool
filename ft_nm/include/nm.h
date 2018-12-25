
#ifndef NM_H
#define NM_H

typedef struct 	symtab {
	uint8_t  	*n_name;
	uint8_t  	n_type;
	uint8_t  	n_sect;
	uint16_t 	n_desc;
	uint64_t 	n_value;
}				symtab_t;

int     nm_read_file(const char *path, void *ptr);
int		nm_macho32(void *ptr);
int		nm_macho64(void *ptr);

void 	sort_symtab(struct symtab *arr, size_t n);

void    error(const char *prefix, const char *str);
void    error_custom(const char *prefix, const char *str, const char *err);
void    terminate(const char *prefix, const char *str);
void    terminate_custom(const char *prefix, const char *str, const char *err);

#endif /* NM_H */
