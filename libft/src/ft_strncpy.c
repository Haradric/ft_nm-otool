/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:32:51 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 15:32:54 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*str;

	str = dst;
	while (*src != '\0' && len > 0)
	{
		*str++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*str++ = '\0';
		len--;
	}
	return (dst);
}
