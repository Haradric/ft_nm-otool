/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisinlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:12:30 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:12:31 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstisinlist(t_list *list, t_list *elem)
{
	t_list	*last;

	if (!list || !elem)
		return (0);
	last = list;
	while (last)
	{
		if (last == elem)
			return (1);
		last = last->next;
	}
	return (0);
}
