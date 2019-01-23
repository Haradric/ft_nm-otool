/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_otool.h"

static void	print_arch(uint32_t arch)
{
	if (arch && arch != HOSTARCH)
	{
		write(STDOUT_FILENO, " - ", 3);
		if (arch == CPU_TYPE_I386)
			write(STDOUT_FILENO, "i386", 4);
		else if (arch == CPU_TYPE_X86_64)
			write(STDOUT_FILENO, "x86_64", 6);
		else if (arch == CPU_TYPE_POWERPC)
			write(STDOUT_FILENO, "ppc", 3);
		else if (arch == CPU_TYPE_POWERPC64)
			write(STDOUT_FILENO, "ppc64", 5);
		else
			write(STDOUT_FILENO, "unknown", 7);
	}
}

void		print_filename(const char *name, uint32_t arch)
{
	if (name)
	{
		write(STDOUT_FILENO, name, ft_strlen(name));
		print_arch(arch);
		write(STDOUT_FILENO, ":\n", 2);
	}
}
