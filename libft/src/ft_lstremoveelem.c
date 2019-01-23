/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveelem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:12:49 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:12:50 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveelem(t_list **list, t_list *elem)
{
	if (!(*list) || !elem || !ft_lstisinlist(*list, elem))
		return ;
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		*list = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	elem->prev = NULL;
	elem->next = NULL;
}
