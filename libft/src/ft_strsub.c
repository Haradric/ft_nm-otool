/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:06:56 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/28 19:07:04 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*sub;

	if (!s || start > ft_strlen(s))
		return (NULL);
	str = (char *)s + start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	*(sub + len) = '\0';
	ft_strncpy(sub, str, len);
	return (sub);
}
