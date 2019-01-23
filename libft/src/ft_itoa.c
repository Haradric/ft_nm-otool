/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:22:15 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/29 14:22:19 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n >= 0)
	{
		*(str + --len) = '0' + (n % 10);
		n /= 10;
		while (n > 0)
		{
			*(str + --len) = '0' + (n % 10);
			n /= 10;
		}
		return (str);
	}
	str[0] = '-';
	while (n)
	{
		*(str + --len) = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}
