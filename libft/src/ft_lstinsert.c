/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:42:07 by mbraslav          #+#    #+#             */
/*   Updated: 2017/06/14 14:42:09 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **list, t_list *prev, t_list *elem, t_list *next)
{
	t_list	*last;

	if (!*list || !elem)
		return ;
	last = ft_lstgetlast(elem);
	if (prev)
		prev->next = elem;
	else
		*list = elem;
	elem->prev = prev;
	if (next)
		next->prev = last;
	last->next = next;
}
