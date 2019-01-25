/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_otool.h"

static void	print_text_sect(void *ptr, uint64_t size, uint64_t vm_addr)
{
	char const	*msg = "Contents of (" SEG_TEXT "," SECT_TEXT ") section\n";
	int const	step = 16;
	void		*end;
	size_t		i;

	write(STDOUT_FILENO, msg, ft_strlen(msg));
	end = ptr + size;
	while (ptr < end)
	{
		write(STDOUT_FILENO, htsu64(vm_addr), 16);
		write(STDOUT_FILENO, "\t", 1);
		i = 0;
		while (ptr + i < end && i < step)
		{
			write(STDOUT_FILENO, htsu8(*(uint8_t *)(ptr + i)), 2);
			write(STDOUT_FILENO, " ", 1);
			i++;
		}
		write(STDOUT_FILENO, "\n", 1);
		vm_addr += step;
		ptr += step;
	}
	if (get_mode())
		write(STDOUT_FILENO, "\n", 1);
}

static void	read_segment(void *ptr, struct segment_command_64 *cmd)
{
	struct section_64	*sect;
	size_t				i;

	sect = (void *)cmd + sizeof(*cmd);
	i = 0;
	while (i < cmd->nsects)
	{
		if (!ft_strcmp(sect[i].segname, SEG_TEXT) &&
			!ft_strcmp(sect[i].sectname, SECT_TEXT))
			print_text_sect(ptr + sect[i].offset, sect[i].size, sect[i].addr);
		i++;
	}
}

void		get_text_sect64(void *ptr)
{
	struct load_command	*lc;
	uint32_t			ncmds;

	lc = ptr + sizeof(struct mach_header_64);
	ncmds = ((struct mach_header_64 *)ptr)->ncmds;
	while (ncmds--)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			read_segment(ptr, (void *)lc);
		}
		lc = (void *)lc + lc->cmdsize;
	}
}
