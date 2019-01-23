/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:42:43 by mbraslav          #+#    #+#             */
/*   Updated: 2017/06/14 14:42:45 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **list, t_list *elem)
{
	t_list	*last;

	if (!(*list))
	{
		*list = elem;
		return ;
	}
	if (!elem)
		return ;
	last = ft_lstgetlast(*list);
	last->next = elem;
	elem->prev = last;
	elem->next = NULL;
}
