/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:08:28 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/30 20:08:32 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*last;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	last = new;
	while (lst->next)
	{
		last->next = f(lst->next);
		last = last->next;
		lst = lst->next;
	}
	return (new);
}
