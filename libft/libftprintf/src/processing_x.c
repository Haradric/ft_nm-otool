/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:38:36 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 16:22:09 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	standard_form(t_description *conversion)
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

static void	alternate_form(t_description *conversion)
{
	int		len;
	int		diff;

	len = (int)ft_strlen(conversion->result);
	if (conversion->flag.zero == 0)
		expand_str(&conversion->result, "0x", 0);
	else
		conversion->width -= 2;
	standard_form(conversion);
	if (conversion->flag.zero == 1)
	{
		if ((diff = (int)ft_strlen(conversion->result - len)) >= 2)
			while (diff-- > 0)
				expand_str(&conversion->result, " ", 0);
		expand_str(&conversion->result, "0x", 0);
	}
}

static void	apply_precision(t_description *conversion)
{
	int		n;

	if ((n = conversion->precision - (int)ft_strlen(conversion->result)) > 0)
		while (n-- > 0)
			expand_str(&conversion->result, "0", 0);
}

size_t		processing_x(t_description *conversion)
{
	conversion->result = uitoa_base(conversion->param.uinteger, 16);
	apply_precision(conversion);
	if (conversion->param.uinteger == 0 && conversion->precision == 0)
	{
		free(conversion->result);
		conversion->result = ft_strnew(0);
	}
	if (conversion->flag.hash == 0 || conversion->param.uinteger == 0)
		standard_form(conversion);
	else
		alternate_form(conversion);
	if (conversion->type == 'X')
		ft_strtoupper(conversion->result);
	conversion->len = (int)ft_strlen(conversion->result);
	return (conversion->len);
}
