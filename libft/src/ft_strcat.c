/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:33:49 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 15:33:56 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(s1);
	srclen = ft_strlen(s2);
	ft_memcpy(s1 + dstlen, s2, srclen + 1);
	return (s1);
}
