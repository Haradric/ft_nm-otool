/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:23:20 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/13 14:23:22 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precision(t_description *conversion)
{
	char	*new;
	size_t	len;

	if (conversion->precision == -1 ||
		(conversion->precision >= (int)ft_strlen(conversion->result)))
		len = ft_strlen(conversion->result);
	else
		len = conversion->precision;
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

size_t		processing_s(t_description *conversion)
{
	if (conversion->type == 'S' ||
		(conversion->type == 's' && conversion->length == 3))
		return (processing_ls(conversion));
	if (conversion->param.string == NULL)
	{
		if (conversion->width != 0 && conversion->flag.zero == 1)
			conversion->result = ft_strnew(0);
		else
		{
			conversion->result = NULL;
			return (0);
		}
	}
	else
		conversion->result = ft_strdup(conversion->param.string);
	apply_precision(conversion);
	apply_width(conversion);
	conversion->len = (int)ft_strlen(conversion->result);
	return (conversion->len);
}
