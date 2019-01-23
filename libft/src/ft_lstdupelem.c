/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:09:30 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:09:32 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdupelem(t_list *elem)
{
	t_list	*dup;

	if (!elem)
		return (NULL);
	dup = ft_lstnew(elem->content, elem->content_size);
	dup->prev = elem->prev;
	dup->next = elem->next;
	return (dup);
}
