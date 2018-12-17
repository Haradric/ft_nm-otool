
#ifndef NM_H
#define NM_H

int     read_mach_o(const char *path, void *ptr);

void    error(const char *prefix, const char *str);
void    error_custom(const char *prefix, const char *str, const char *err);
void    terminate(const char *prefix, const char *str);
void    terminate_custom(const char *prefix, const char *str, const char *err);

#endif /* NM_H */
