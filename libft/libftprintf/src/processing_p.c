/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:58:39 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/22 12:58:40 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precision(t_description *conversion)
{
	int		n;

	if ((n = conversion->precision - (int)ft_strlen(conversion->result)) > 0)
		while (n-- > 0)
			expand_str(&conversion->result, "0", 0);
}

static void	apply_width(t_description *conversion)
{
	int		diff;
	int		pos;
	char	*filler;

	diff = conversion->width - (int)ft_strlen(conversion->result);
	pos = (conversion->flag.minus == 1) ? 1 : 0;
	filler = ft_strdup((conversion->flag.zero == 1) ? "0" : " ");
	diff -= 2;
	if (conversion->flag.zero == 0)
		expand_str(&conversion->result, "0x", 0);
	if (diff > 0)
		while (diff-- > 0)
			expand_str(&conversion->result, filler, pos);
	free(filler);
	if (conversion->flag.zero == 1)
		expand_str(&conversion->result, "0x", 0);
}

size_t		processing_p(t_description *conversion)
{
	if (conversion->param.pointer == NULL && conversion->precision == 0)
		conversion->result = ft_strnew(0);
	else
		conversion->result =
		uitoa_base((uintmax_t)conversion->param.pointer, 16);
	apply_precision(conversion);
	apply_width(conversion);
	conversion->len = (int)ft_strlen(conversion->result);
	return (conversion->len);
}
