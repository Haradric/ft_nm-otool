/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:38:24 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/10 12:38:27 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	processing_percent(t_description *conversion)
{
	int		diff;
	char	*filler;
	int		pos;

	conversion->result = ft_strnew(1);
	conversion->result[0] = '%';
	diff = conversion->width - (int)ft_strlen(conversion->result);
	if (conversion->flag.zero == 1 && conversion->flag.minus != 1)
		filler = ft_strdup("0");
	else
		filler = ft_strdup(" ");
	pos = (conversion->flag.minus == 1) ? 1 : 0;
	if (diff > 0)
		while (diff-- > 0)
			expand_str(&conversion->result, filler, pos);
	free(filler);
	conversion->len = (int)ft_strlen(conversion->result);
	return (conversion->len);
}
