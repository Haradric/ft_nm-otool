/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:23:23 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/27 17:23:26 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				found;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			found = 1;
			j = 0;
			while (little[j] && found)
			{
				if (big[i + j] != little[j])
					found = 0;
				j++;
			}
			if (found && (i + j) <= len)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
