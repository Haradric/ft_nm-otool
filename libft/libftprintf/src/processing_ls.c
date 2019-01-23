/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:27:00 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/27 14:27:01 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precision(t_description *conversion)
{
	char	*new;
	size_t	len;
	wchar_t	*s;

	if (conversion->precision == -1 ||
		(conversion->precision >= (int)ft_strlen(conversion->result)))
		len = (int)ft_strlen(conversion->result);
	else
	{
		len = 0;
		s = conversion->param.maxstring;
		while ((int)len + (int)wchar_len(*s) <= conversion->precision)
			len += wchar_len(*s++);
	}
	new = ft_strsub(conversion->result, 0, len);
	free(conversion->result);
	conversion->result = new;
}

static void	apply_width(t_description *conversion)
{
	char	*filler;
	int		diff;
	int		pos;

	diff = conversion->width - (int)ft_strlen(conversion->result);
	pos = (conversion->flag.minus == 1) ? 1 : 0;
	if (conversion->flag.zero == 1 && conversion->flag.minus != 1)
		filler = ft_strdup("0");
	else
		filler = ft_strdup(" ");
	if (diff > 0)
		while (diff-- > 0)
			expand_str(&conversion->result, filler, pos);
	free(filler);
}

static char	*wchar_str_to_char(const wchar_t *str)
{
	wchar_t	*s1;
	char	*s2;
	char	*wchar;

	s1 = (wchar_t *)str;
	s2 = ft_strnew(0);
	while (*s1)
	{
		wchar = wchar_to_char(*s1);
		expand_str(&s2, wchar, 1);
		free(wchar);
		s1++;
	}
	return (s2);
}

size_t		processing_ls(t_description *conversion)
{
	if (conversion->param.maxstring == NULL)
	{
		if (conversion->width == 0)
		{
			conversion->result = NULL;
			return (0);
		}
		else
			conversion->result = ft_strnew(0);
	}
	else
		conversion->result = wchar_str_to_char(conversion->param.maxstring);
	apply_precision(conversion);
	apply_width(conversion);
	conversion->len += ft_strlen(conversion->result);
	return (conversion->len);
}
