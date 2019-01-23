/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:13:44 by mbraslav          #+#    #+#             */
/*   Updated: 2017/07/05 16:13:44 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t wchar)
{
	if (wchar > 0 && wchar < 127)
		return (1);
	else if (wchar > 128 && wchar < 2047)
		return (2);
	else if (wchar > 2048 && wchar < 65535)
		return (3);
	else if (wchar > 65536 && wchar < 2097151)
		return (4);
	else if (wchar > 2097152 && wchar < 67108863)
		return (5);
	else
		return (6);
}
