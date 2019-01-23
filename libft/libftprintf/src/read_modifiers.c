/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:15:44 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/08 13:15:46 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width_from_param(t_description *conversion)
{
	conversion->width = va_arg(conversion->args, int);
	if (conversion->width < 0)
	{
		conversion->flag.minus = 1;
		conversion->width *= -1;
	}
}

void	get_precision_from_param(t_description *conversion)
{
	conversion->precision = va_arg(conversion->args, int);
	if (conversion->precision < 0)
		conversion->precision = -1;
}

size_t	read_modifiers(const char *str, t_description *conversion)
{
	size_t	len;
	size_t	diff;

	len = 1;
	diff = len;
	while (diff != 0)
	{
		diff = len;
		len += read_flags(str + len, conversion);
		len += read_width(str + len, conversion);
		len += read_precision(str + len, conversion);
		len += read_length(str + len, conversion);
		diff = len - diff;
	}
	len += read_type(str + len, conversion);
	if (conversion->type != '%' && conversion->type != '0' &&
		conversion->type != '\0')
		read_args(conversion);
	return (len);
}
