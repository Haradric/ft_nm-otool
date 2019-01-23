/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:55:35 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 16:55:42 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	int		free;
	size_t	srclen;
	int		i;
	char	*d;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	free = (int)size - (int)dstlen - 1;
	d = dst + dstlen;
	i = 0;
	while (i < free && src[i] != '\0')
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (((dstlen < size) ? dstlen : size) + srclen);
}
