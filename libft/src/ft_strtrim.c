/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:56:26 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/30 10:56:41 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		finish;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (ft_strnew(1));
	start = i;
	i = 0;
	while (s[i])
		i++;
	i--;
	while (ft_isspace(s[i]))
		i--;
	finish = i;
	str = ft_strsub(s, start, finish - start + 1);
	return (str);
}
