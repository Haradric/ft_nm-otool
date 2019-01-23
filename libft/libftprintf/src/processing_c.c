/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:50:51 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 16:19:28 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_width(t_description *conversion)
{
	char	*filler;
	int		diff;
	int		pos;

	diff = conversion->width - (int)ft_strlen(conversion->result);
	diff -= (conversion->result[0] == '\0') ? 1 : 0;
	pos = (conversion->flag.minus == 1) ? 1 : 0;
	if (!ft_memcmp(conversion->result, "\0", 1) && conversion->flag.minus == 1)
	{
		free(conversion->result);
		conversion->result = ft_strnew(diff + 2);
		ft_memset(conversion->result + 1, (conversion->flag.zero == 1 &&
conversion->flag.minus != 1) ? '0' : ' ', diff);
		conversion->len += diff;
		return ;
	}
	if (conversion->flag.zero == 1 && conversion->flag.minus != 1)
		filler = ft_strdup("0");
	else
		filler = ft_strdup(" ");
	if (diff > 0)
		while (diff-- > 0)
			expand_str(&conversion->result, filler, pos);
	free(filler);
}

size_t		processing_c(t_description *conversion)
{
	conversion->result = ft_strnew(1);
	if ((conversion->type == 'C' && conversion->param.maxchar != 0)
		|| (conversion->type == 'c' && conversion->length == 3 &&
			conversion->param.maxchar != 0))
		conversion->result[0] = (char)conversion->param.maxchar;
	else
	{
		if (conversion->param.maxchar == 0 && conversion->param.ch == 0)
		{
			conversion->result[0] = 0;
			conversion->len++;
		}
		else
			conversion->result[0] = conversion->param.ch;
	}
	apply_width(conversion);
	conversion->len += ft_strlen(conversion->result);
	return (conversion->len);
}
