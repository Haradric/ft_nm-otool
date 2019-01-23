/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:05:18 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/06 19:05:19 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **list, int (*cmp)(void *a, void *b))
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
			if (cmp(last, last->next) > 0)
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
