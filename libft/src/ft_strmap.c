/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:23:31 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/28 18:23:42 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	char	*res;

	if (!s)
		return (NULL);
	s2 = malloc(ft_strlen(s) + 1);
	if (s2 == NULL)
		return (NULL);
	res = s2;
	while (*s)
		*s2++ = f(*s++);
	*s2 = '\0';
	return (res);
}
