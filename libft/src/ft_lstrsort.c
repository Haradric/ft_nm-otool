/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:21:35 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/22 15:21:37 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrsort(t_list **list, int (*cmp)(void *a, void *b))
{
	t_list	*sorted;
	t_list	*last;
	int		swapped;

	swapped = 1;
	sorted = NULL;
	while (swapped == 1)
	{
		swapped = 0;
		last = *list;
		while (last->next)
		{
			if (cmp(last, last->next) < 0)
			{
				ft_lstswap(list, last, last->next);
				swapped = 1;
			}
			if (last->next == NULL || last->next == sorted)
			{
				sorted = last;
				continue ;
			}
			last = last->next;
		}
	}
}
