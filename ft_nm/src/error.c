/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "libft.h"

void	error(const char *prefix, const char *str)
{
	char *err;

	err = strerror(errno);
	write(STDERR_FILENO, prefix, ft_strlen(prefix));
	if (str)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, str, ft_strlen(str));
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}

void	error_custom(const char *prefix, const char *str, const char *err)
{
	write(STDERR_FILENO, prefix, ft_strlen(prefix));
	if (str)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, str, ft_strlen(str));
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}

void	terminate(const char *prefix, const char *str)
{
	error(prefix, str);
	exit(EXIT_FAILURE);
}

void	terminate_custom(const char *prefix, const char *str, const char *err)
{
	error_custom(prefix, str, err);
	exit(EXIT_FAILURE);
}
