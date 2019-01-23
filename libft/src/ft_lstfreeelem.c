/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:09:54 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:09:55 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfreeelem(t_list **list, t_list *elem, \
						void (*freecont)(void *content))
{
	if (!(*list) || !elem || !ft_lstisinlist(*list, elem))
		return ;
	ft_lstremoveelem(list, elem);
	if (freecont)
		freecont(elem->content);
	free(elem);
}
