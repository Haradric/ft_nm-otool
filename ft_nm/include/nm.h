
#ifndef NM_H
#define NM_H

typedef struct 	symtab {
	uint8_t  	*n_name;
	uint8_t  	n_type;
	uint8_t  	n_sect;
	uint16_t 	n_desc;
	uint64_t 	n_value;
}				symtab_t;

int     read_mach_o(const char *path, void *ptr);

void    error(const char *prefix, const char *str);
void    error_custom(const char *prefix, const char *str, const char *err);
void    terminate(const char *prefix, const char *str);
void    terminate_custom(const char *prefix, const char *str, const char *err);

void 	sort_symtab(struct symtab *arr, size_t n);

#endif /* NM_H */
