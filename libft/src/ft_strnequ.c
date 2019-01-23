/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:24:18 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/28 18:24:22 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t len)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && i < len)
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i])
			return (0);
		i++;
	}
	return ((((unsigned char)s1[i] - (unsigned char)s2[i])
	&& (i != len)) ? 0 : 1);
}
