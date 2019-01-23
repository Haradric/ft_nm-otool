/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:21:05 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/27 17:21:15 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			found = 1;
			while (little[j] && found)
			{
				if (big[i + j] != little[j])
					found = 0;
				j++;
			}
			if (found)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
