/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:33:17 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 18:40:01 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(s1);
	srclen = ft_strlen(s2);
	len = (srclen < n) ? srclen : n;
	ft_memcpy(s1 + dstlen, s2, len);
	s1[dstlen + len] = '\0';
	return (s1);
}
