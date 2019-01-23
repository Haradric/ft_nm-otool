/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:42:50 by mbraslav          #+#    #+#             */
/*   Updated: 2017/06/14 14:42:51 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **list, t_list *elem)
{
	if (elem == NULL)
		return ;
	if (*list == NULL)
	{
		elem->next = NULL;
	}
	else
	{
		(*list)->prev = elem;
		elem->next = *list;
	}
	elem->prev = NULL;
	*list = elem;
}
