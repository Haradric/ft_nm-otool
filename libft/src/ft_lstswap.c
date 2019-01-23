/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:05:06 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/06 19:05:08 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstswap(t_list **list, t_list *x, t_list *y)
{
	t_list	*x_prev;
	t_list	*y_prev;

	if (!(*list) || x == y || \
		!ft_lstisinlist(*list, x) || !ft_lstisinlist(*list, y))
		return ;
	x_prev = x->prev;
	y_prev = y->prev;
	if (x == y_prev)
	{
		ft_lstremoveelem(list, y);
		ft_lstinsert(list, x->prev, y, x);
	}
	else if (y == x_prev)
	{
		ft_lstremoveelem(list, x);
		ft_lstinsert(list, y->prev, x, y);
	}
	else
	{
		ft_lstremoveelem(list, y);
		ft_lstinsert(list, x->prev, y, x->next);
		ft_lstremoveelem(list, x);
		ft_lstinsert(list, y_prev, x, y_prev->next);
	}
}
