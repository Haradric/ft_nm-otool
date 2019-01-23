/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:39:19 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/30 13:39:24 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*start;
	int		i;

	if (!s || !(arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			arr[i++] = ft_strsub(start, 0, s - start);
		}
		if (*s == '\0')
			break ;
		s++;
	}
	arr[i] = NULL;
	return (arr);
}
