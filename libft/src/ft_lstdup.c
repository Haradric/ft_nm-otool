/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:09:14 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:09:16 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *list)
{
	t_list	*duplist;
	t_list	*dupelem;

	duplist = NULL;
	while (list)
	{
		dupelem = ft_lstnew(list->content, list->content_size);
		ft_lstpushback(&duplist, dupelem);
		list = list->next;
	}
	return (duplist);
}
