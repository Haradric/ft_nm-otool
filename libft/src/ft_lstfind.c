/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:14:43 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:14:44 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *list, void *content, size_t content_size)
{
	if (!list || !content_size || !content)
		return (NULL);
	while (list)
	{
		if (content_size == list->content_size \
			&& !ft_memcmp(list->content, content, content_size))
			return (list);
		list = list->next;
	}
	return (NULL);
}
