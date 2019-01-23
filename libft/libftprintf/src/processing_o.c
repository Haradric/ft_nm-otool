/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:50:12 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 16:13:30 by mbraslav         ###   ########.fr       */
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
	size_t	len;
	int		diff;

	len = ft_strlen(conversion->result);
	if (conversion->flag.zero == 0 && conversion->param.uinteger != 0)
		expand_str(&conversion->result, "0", 0);
	else if (!(conversion->param.uinteger == 0 && conversion->precision == 0))
		conversion->width -= 1;
	standard_form(conversion);
	if (conversion->flag.zero == 1)
	{
		if ((diff = (int)ft_strlen(conversion->result - len)) >= 1)
			while (diff-- > 0)
				expand_str(&conversion->result, " ", 0);
		expand_str(&conversion->result, "0", 0);
	}
}

static void	apply_precision(t_description *conversion)
{
	int		n;

	if ((n = conversion->precision - (int)ft_strlen(conversion->result)) > 0)
	{
		if (conversion->flag.hash == 1 && n > 0)
			n--;
		while (n-- > 0)
			expand_str(&conversion->result, "0", 0);
	}
}

size_t		processing_o(t_description *conversion)
{
	conversion->result = uitoa_base(conversion->param.uinteger, 8);
	apply_precision(conversion);
	if (conversion->param.uinteger == 0 && conversion->precision == 0 &&
		conversion->flag.hash != 1)
	{
		free(conversion->result);
		conversion->result = ft_strnew(0);
	}
	if (conversion->flag.hash == 0)
		standard_form(conversion);
	else
		alternate_form(conversion);
	conversion->len = ft_strlen(conversion->result);
	return (conversion->len);
}
