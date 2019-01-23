/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:30:06 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/25 15:30:07 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetelem(t_list *list, size_t index)
{
	if (!list)
		return (NULL);
	while (list && index)
	{
		list = list->next;
		index--;
	}
	if (index)
		return (NULL);
	return (list);
}
