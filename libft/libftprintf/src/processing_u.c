/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:07:48 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 17:07:53 by mbraslav         ###   ########.fr       */
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

size_t		processing_u(t_description *conversion)
{
	conversion->result = uitoa_base(conversion->param.uinteger, 10);
	if (conversion->param.uinteger == 0)
	{
		free(conversion->result);
		conversion->result = ft_strdup((conversion->precision == 0) ? "" : "0");
	}
	apply_precision(conversion);
	apply_width(conversion);
	conversion->len = (int)ft_strlen(conversion->result);
	return (conversion->len);
}
