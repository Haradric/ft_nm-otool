/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:50:46 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 16:11:53 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	process_modifiers(t_description *conversion)
{
	size_t	len;
	char	type;

	type = conversion->type;
	len = 0;
	if (type == '%')
		len += processing_percent(conversion);
	else if (type == 'x' || type == 'X')
		len += processing_x(conversion);
	else if (type == 's' || type == 'S')
		len += processing_s(conversion);
	else if (type == 'c' || type == 'C' || type == '0')
		len += processing_c(conversion);
	else if (type == 'o' || type == 'O')
		len += processing_o(conversion);
	else if (type == 'd' || type == 'i' || type == 'D')
		len += processing_di(conversion);
	else if (type == 'u' || type == 'U')
		len += processing_u(conversion);
	else if (type == 'p')
		len += processing_p(conversion);
	else if (type == 0)
		conversion->result = ft_strnew(0);
	return (len);
}
