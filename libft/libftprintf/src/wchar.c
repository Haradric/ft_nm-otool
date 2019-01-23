/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:51:59 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/27 13:52:00 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	wchar_len(wchar_t wchar)
{
	if (wchar > 0 && wchar < 127)
		return (1);
	else if (wchar > 128 && wchar < 2047)
		return (2);
	else if (wchar > 2048 && wchar < 65535)
		return (3);
	else if (wchar > 65536 && wchar < 2097151)
		return (4);
	else if (wchar > 2097152 && wchar < 67108863)
		return (5);
	else
		return (6);
}

char	*wchar_to_char(wchar_t wchar)
{
	char	*s;
	size_t	len;
	size_t	n;

	len = wchar_len(wchar);
	s = ft_strnew(len + 1);
	if (len == 1)
	{
		*s = (char)wchar;
		return (s);
	}
	n = len;
	while (n)
	{
		if (n != 1)
		{
			*(s + (n - 1)) = wchar % 64 + 128;
			wchar >>= 6;
		}
		n--;
	}
	*s = power(2, 8) - power(2, 8 - len) + wchar;
	return (s);
}
