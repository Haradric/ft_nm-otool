/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	fat_check_own(struct fat_arch *arch, size_t n)
{
	uint32_t i;

	i = 0;
	while (i < n)
	{
		if (btlu32(arch[i].cputype) == HOSTARCH)
			return (1);
		i++;
	}
	return (0);
}

int			read_fat(const char *name, void *ptr, int multifile)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					own;
	uint32_t			n;
	uint32_t			i;

	header = ptr;
	arch = ptr + sizeof(*header);
	n = btlu32(header->nfat_arch);
	own = fat_check_own(arch, n);
	i = -1;
	while (++i < n)
	{
		if (own && btlu32(arch[i].cputype) != HOSTARCH)
			continue;
		nm_read_file(name, ptr + btlu32(arch[i].offset), btlu32(arch[i].size),
			multifile);
	}
	return (0);
}
