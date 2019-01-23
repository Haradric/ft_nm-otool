/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:22:39 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/27 17:22:43 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char chr1;
	unsigned char chr2;

	while (n--)
	{
		chr1 = *(unsigned char *)s1;
		chr2 = *(unsigned char *)s2;
		if (chr1 != chr2)
			return (chr1 - chr2);
		s1++;
		s2++;
	}
	return (0);
}
