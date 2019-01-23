/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

uint32_t btlu32(uint32_t x) {
    x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);

    return (x << 16) | (x >> 16);
}

char *genname(char *name, char *sub) {

    char *str = ft_memalloc(ft_strlen(name) + ft_strlen(sub) + 3);
    char *s;

    s = str;
    while(*name)
        *s++ = *name++;

    *s++ = '(';
    while(*sub)
        *s++ = *sub++;
    *s++ = ')';

    *s = 0;

    return (str);
}
