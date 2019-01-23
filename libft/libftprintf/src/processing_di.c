/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:46:18 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 16:17:04 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	absolute(intmax_t n)
{
	return ((n >= 0) ? n : n * -1);
}

static void		apply_precision(t_description *conversion)
{
	int		n;

	if ((n = conversion->precision - (int)ft_strlen(conversion->result)) > 0)
		while (n-- > 0)
			expand_str(&conversion->result, "0", 0);
}

static void		apply_width(t_description *conversion)
{
	char	*filler;
	int		diff;
	int		pos;

	diff = conversion->width - (int)ft_strlen(conversion->result);
	pos = (conversion->flag.minus == 1) ? 1 : 0;
	if (conversion->flag.zero == 1 && conversion->flag.minus
		!= 1 && conversion->precision == -1)
		filler = ft_strdup("0");
	else
		filler = ft_strdup(" ");
	if (diff > 0)
		while (diff-- > 0)
			expand_str(&conversion->result, filler, pos);
	free(filler);
}

static void		add_sign(t_description *conversion)
{
	if (conversion->param.integer < 0)
		expand_str(&conversion->result, "-", 0);
	else if (conversion->param.integer >= 0 && conversion->flag.plus == 1)
		expand_str(&conversion->result, "+", 0);
	else if (conversion->param.integer >= 0 && conversion->flag.space == 1 &&
		conversion->flag.plus == 0)
		expand_str(&conversion->result, " ", 0);
	else
		return ;
}

size_t			processing_di(t_description *conversion)
{
	if ((conversion->param.integer / 2) == -4611686018427387904)
		conversion->result = ft_strdup("9223372036854775808");
	else
		conversion->result = itoa_base(absolute(conversion->param.integer), 10);
	if (conversion->param.integer == 0)
	{
		free(conversion->result);
		conversion->result = ft_strdup((conversion->precision == 0) ? "" : "0");
	}
	apply_precision(conversion);
	if (conversion->flag.zero == 1)
	{
		if (conversion->param.integer < 0 || conversion->flag.plus == 1 ||
			conversion->flag.space == 1)
			conversion->width -= 1;
		apply_width(conversion);
		add_sign(conversion);
	}
	else
	{
		add_sign(conversion);
		apply_width(conversion);
	}
	conversion->len = ft_strlen(conversion->result);
	return (conversion->len);
}
