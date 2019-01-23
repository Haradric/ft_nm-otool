/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

#define UINT64_STR_LEN 16
#define UINT32_STR_LEN 8
#define UINT8_STR_LEN  2

uint32_t	btlu32(uint32_t x)
{
	x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
	return (x << 16) | (x >> 16);
}

char		*htsu8(uint8_t n)
{
	static char	buff[UINT8_STR_LEN + 1] = { 0 };
	const char	*hex = "0123456789abcdef";
	uint8_t		i;

	buff[UINT8_STR_LEN] = 0;
	i = UINT8_STR_LEN - 1;
	while (i < 16)
	{
		buff[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	return ((char *)&buff);
}

char		*htsu32(uint32_t n)
{
	static char	buff[UINT32_STR_LEN + 1] = { 0 };
	const char	*hex = "0123456789abcdef";
	uint8_t		i;

	buff[UINT32_STR_LEN] = 0;
	i = UINT32_STR_LEN - 1;
	while (i < 16)
	{
		buff[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	return ((char *)&buff);
}

char		*htsu64(uint64_t n)
{
	static char	buff[UINT64_STR_LEN + 1] = { 0 };
	const char	*hex = "0123456789abcdef";
	uint8_t		i;

	buff[UINT64_STR_LEN] = 0;
	i = UINT64_STR_LEN - 1;
	while (i < 16)
	{
		buff[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	return ((char *)&buff);
}

char		*genname(char *name, char *sub)
{
	char	*str;
	char	*s;

	str = ft_memalloc(ft_strlen(name) + ft_strlen(sub) + 3);
	s = str;
	while (*name)
		*s++ = *name++;
	*s++ = '(';
	while (*sub)
		*s++ = *sub++;
	*s++ = ')';
	*s = 0;
	return (str);
}
