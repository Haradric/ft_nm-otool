/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:04:38 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/01 18:04:42 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_format(t_description *conversion, int fd)
{
	if (conversion->result == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	else
	{
		write(fd, conversion->result, conversion->len);
		return (conversion->len);
	}
}

int		ft_printf(const char *format, ...)
{
	char			*str;
	t_description	conversion;
	size_t			len;
	int				fd;

	fd = 1;
	len = 0;
	str = (char *)format;
	va_start(conversion.args, format);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			clean_description(&conversion);
			str += read_modifiers(str, &conversion);
			process_modifiers(&conversion);
			len += print_format(&conversion, fd);
			free(conversion.result);
			continue ;
		}
		write(fd, str++, 1);
		len++;
	}
	va_end(conversion.args);
	return ((int)len);
}
