/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:07:17 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/03 16:07:19 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	expand_str(char **s1, const char *s2, int pos)
{
	char	*new;

	if (pos == 0)
		new = ft_strjoin(s2, *s1);
	else if (pos == 1)
		new = ft_strjoin(*s1, s2);
	else
		return ;
	free(*s1);
	*s1 = new;
}

char	*itoa_base(intmax_t n, int base)
{
	intmax_t	temp;
	char		*str;
	int			len;
	int			sign;

	len = 1;
	sign = (base == 10 && n < 0) ? -1 : 1;
	n *= sign;
	temp = n;
	while ((temp >= base) && (++len > 0))
		temp /= base;
	if (!(str = (char *)malloc(sizeof(char) * (len + ((sign == -1) ? 2 : 1)))))
		return (NULL);
	*(str + len) = '\0';
	while (len > 0)
	{
		temp = n % base;
		*(str + --len) = (temp >= 10) ? temp - 10 + 'a' : temp + '0';
		n /= base;
	}
	if (sign == -1)
		expand_str(&str, "-", 0);
	return (str);
}

char	*uitoa_base(uintmax_t n, int base)
{
	uintmax_t	temp;
	char		*str;
	int			len;

	len = 1;
	temp = n;
	while ((temp >= (uintmax_t)base) && (++len > 0))
		temp /= base;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(str + len) = '\0';
	while (len > 0)
	{
		temp = n % base;
		*(str + --len) = (temp >= 10) ? temp - 10 + 'a' : temp + '0';
		n /= base;
	}
	return (str);
}

int		power(int x, size_t n)
{
	if (n == 0)
		return (1);
	return (x * power(x, n - 1));
}
