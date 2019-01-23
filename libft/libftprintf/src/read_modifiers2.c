/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_modifiers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:15:53 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/08 13:15:54 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	read_flags(const char *str, t_description *conversion)
{
	size_t	len;
	char	*flag;

	len = 0;
	while (*str != '\0' && (flag = ft_strchr("-+ #0", *str)))
	{
		if (*flag == '-')
			conversion->flag.minus = 1;
		else if (*flag == '+')
			conversion->flag.plus = 1;
		else if (*flag == ' ')
			conversion->flag.space = 1;
		else if (*flag == '#')
			conversion->flag.hash = 1;
		else if (*flag == '0')
			conversion->flag.zero = 1;
		str++;
		len++;
	}
	return (len);
}

size_t	read_width(const char *str, t_description *conversion)
{
	size_t	len;

	len = 0;
	if (ft_isdigit(*(str + len)) || *(str + len) == '*')
	{
		while (*(str + len) != '\0' && ft_isdigit(*(str + len)))
			len++;
		if (*(str + len) == '*')
		{
			get_width_from_param(conversion);
			len++;
		}
		else if (len > 0)
			conversion->width = ft_atoi(str);
	}
	return (ft_strlen(str) - ft_strlen(str + len));
}

size_t	read_precision(const char *str, t_description *conversion)
{
	size_t	len;

	len = 0;
	if (*str == '.')
	{
		len++;
		while (*(str + len) != '\0' && ft_isdigit(*(str + len)))
			len++;
		if (*(str + len) == '*')
		{
			get_precision_from_param(conversion);
			len++;
		}
		else if (len > 0)
			conversion->precision = ft_atoi(str + 1);
		else
			conversion->precision = 0;
	}
	return (ft_strlen(str) - ft_strlen(str + len));
}

size_t	read_length(const char *str, t_description *conversion)
{
	size_t	len;
	int		length;

	len = 0;
	if (*str == 'h' && (*(str + 1) == 'h'))
		length = 1;
	else if (*str == 'h' && (*(str + 1) != 'h'))
		length = 2;
	else if (*str == 'l' && (*(str + 1) != 'l'))
		length = 3;
	else if (*str == 'l' && (*(str + 1) == 'l'))
		length = 4;
	else if (*str == 'j')
		length = 5;
	else if (*str == 'z')
		length = 6;
	else
		length = 0;
	len += (length > 0) ? 1 : 0;
	len += (length == 1 || length == 4) ? 1 : 0;
	if (conversion->length == 0 || conversion->length < length)
		conversion->length = length;
	return (len);
}

size_t	read_type(const char *str, t_description *conversion)
{
	char	*type;

	if (*str == '\0')
		return (0);
	else if ((type = ft_strchr("%sSpdDioOuUxXcC", *str)))
	{
		conversion->type = *type;
		return (1);
	}
	else
	{
		conversion->param.ch = (char)*str;
		conversion->type = '0';
		return (1);
	}
}
