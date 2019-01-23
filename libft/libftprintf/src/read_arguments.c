/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:18:46 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/08 14:18:49 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	read_args(t_description *conversion)
{
	if (conversion->length == 0)
		return (taking_without_length(conversion));
	else if (conversion->length == 1)
		return (taking_with_hh(conversion));
	else if (conversion->length == 2)
		return (taking_with_h(conversion));
	else if (conversion->length == 3)
		return (taking_with_l(conversion));
	else if (conversion->length == 4)
		return (taking_with_ll(conversion));
	else if (conversion->length == 5)
		return (taking_with_j(conversion));
	else if (conversion->length == 6)
		return (taking_with_z(conversion));
	else
		return (0);
}

int		taking_without_length(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i')
		conversion->param.integer = va_arg(conversion->args, int);
	else if (ft_strchr("ouxX", conversion->type))
		conversion->param.uinteger = va_arg(conversion->args, unsigned int);
	else if (conversion->type == 'c')
		conversion->param.ch = va_arg(conversion->args, int);
	else if (conversion->type == 's')
		conversion->param.string = va_arg(conversion->args, char *);
	else if (ft_strchr("SDOUC", conversion->type))
		taking_with_l(conversion);
	else if (conversion->type == 'p')
		conversion->param.pointer = va_arg(conversion->args, void *);
	else
		return (0);
	return (1);
}

int		taking_with_hh(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i')
		conversion->param.integer = (char)va_arg(conversion->args, int);
	else if (ft_strchr("ouxX", conversion->type))
		conversion->param.uinteger =
		(unsigned char)va_arg(conversion->args, unsigned int);
	else if (ft_strchr("sSpDOUcC", conversion->type))
		taking_without_length(conversion);
	else
		return (0);
	return (1);
}

int		taking_with_h(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i')
		conversion->param.integer = (short int)va_arg(conversion->args, int);
	else if (ft_strchr("ouxX", conversion->type))
		conversion->param.uinteger =
		(unsigned short int)va_arg(conversion->args, unsigned int);
	else if (ft_strchr("sSpDOUcC", conversion->type))
		taking_without_length(conversion);
	else
		return (0);
	return (1);
}

int		taking_with_l(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i' || type == 'D')
		conversion->param.integer = va_arg(conversion->args, long int);
	else if (ft_strchr("oOuUxX", conversion->type))
		conversion->param.uinteger =
		va_arg(conversion->args, unsigned long int);
	else if (conversion->type == 'c' || conversion->type == 'C')
		conversion->param.maxchar = (wint_t)va_arg(conversion->args, int);
	else if (conversion->type == 's' || conversion->type == 'S')
		conversion->param.maxstring =
		(wchar_t *)va_arg(conversion->args, char *);
	else if (conversion->type == 'p')
		taking_without_length(conversion);
	else
		return (0);
	return (1);
}
