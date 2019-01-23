/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:18:54 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/08 14:18:55 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		taking_with_ll(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i')
		conversion->param.integer = va_arg(conversion->args, long long int);
	else if (ft_strchr("ouxX", conversion->type))
		conversion->param.uinteger =
		va_arg(conversion->args, unsigned long long int);
	else if (ft_strchr("sSpDOUcC", conversion->type))
		taking_without_length(conversion);
	else
		return (0);
	return (1);
}

int		taking_with_j(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i')
		conversion->param.integer = va_arg(conversion->args, intmax_t);
	else if (ft_strchr("ouxX", conversion->type))
		conversion->param.uinteger = va_arg(conversion->args, uintmax_t);
	else if (ft_strchr("sSpDOUcC", conversion->type))
		taking_without_length(conversion);
	else
		return (0);
	return (1);
}

int		taking_with_z(t_description *conversion)
{
	char	type;

	type = conversion->type;
	if (type == 'd' || type == 'i')
		conversion->param.integer = va_arg(conversion->args, size_t);
	else if (ft_strchr("ouxX", conversion->type))
		conversion->param.uinteger = va_arg(conversion->args, size_t);
	else if (ft_strchr("sSpDOUcC", conversion->type))
		taking_without_length(conversion);
	else
		return (0);
	return (1);
}
