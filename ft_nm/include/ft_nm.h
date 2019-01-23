/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:01 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:01 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <ar.h>
# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>

# include "libft.h"

# define AR_MAGIC 0x72613c21

# define HOSTARCH ((sizeof(void *) == 4) ? CPU_TYPE_I386 : CPU_TYPE_X86_64)

typedef struct	s_nm_obj
{
	struct stat	st;
	void		*ptr;
	int			fd;
}				t_nm_obj;

typedef struct	s_symtab
{
	uint8_t		*n_name;
	uint8_t		n_type;
	uint8_t		n_sect;
	uint16_t	n_desc;
	uint64_t	n_value;
}				t_symtab;

typedef struct	s_section_index
{
	uint8_t		nsects;
	uint8_t		text;
	uint8_t		data;
	uint8_t		bss;
}				t_index;

int				nm_read_file(const char *path, void *ptr, size_t size, \
								int multifile);

int				handle_macho32(const char *name, void *ptr);
int				handle_macho64(const char *name, void *ptr);
int				handle_fat(const char *name, void *ptr, int multifile);
int				handle_ar(const char *name, void *ptr, size_t size);

int				read_symtab_macho32(void *ptr, t_symtab **symtab, \
									uint32_t *size);
int				read_symtab_macho64(void *ptr, t_symtab **symtab, \
									uint32_t *size);
int				read_fat(const char *name, void *ptr, int multifile);

void			index_sections(uint32_t ncmds, void *lc_start);
t_index			*get_sect_index(void);

void			sort_symtab(t_symtab *arr, size_t n);

void			print_filename(const char *name, uint32_t arch);

void			print_symtab(t_symtab *tab, size_t size, int addr_size);

void			error(const char *prefix, const char *str);
void			error_custom(const char *prefix, const char *str, \
								const char *err);
void			terminate(const char *prefix, const char *str);
void			terminate_custom(const char *prefix, const char *str, \
									const char *err);

uint32_t		btlu32(uint32_t x);
char			*genname(char *name, char *sub);

#endif
