/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:41:54 by mbraslav          #+#    #+#             */
/*   Updated: 2017/06/14 14:41:55 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetlast(t_list *list)
{
	t_list	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}
