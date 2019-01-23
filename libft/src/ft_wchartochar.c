/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartochar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:16:07 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:16:08 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wchartochar(wchar_t wchar)
{
	char	*s;
	size_t	len;
	size_t	n;

	len = ft_wcharlen(wchar);
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
	*s = ft_power(2, 8) - ft_power(2, 8 - len) + wchar;
	return (s);
}
