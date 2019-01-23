/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:23:48 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/28 18:23:52 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	char			*res;
	unsigned int	i;

	if (!s)
		return (NULL);
	s2 = malloc(ft_strlen(s) + 1);
	if (s2 == NULL)
		return (NULL);
	res = s2;
	i = 0;
	while (*s)
		*s2++ = f(i++, *s++);
	*s2 = '\0';
	return (res);
}
