/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:30:11 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/20 17:30:15 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_flags(t_description *conversion)
{
	conversion->flag.minus = 0;
	conversion->flag.plus = 0;
	conversion->flag.space = 0;
	conversion->flag.hash = 0;
	conversion->flag.zero = 0;
}

void	clean_args(t_description *conversion)
{
	conversion->param.integer = 0;
	conversion->param.uinteger = 0;
	conversion->param.maxstring = NULL;
	conversion->param.maxchar = 0;
	conversion->param.ch = 0;
	conversion->param.string = 0;
	conversion->param.pointer = NULL;
}

void	clean_description(t_description *conversion)
{
	clean_flags(conversion);
	clean_args(conversion);
	conversion->width = 0;
	conversion->precision = -1;
	conversion->length = 0;
	conversion->type = 0;
	conversion->result = NULL;
	conversion->len = 0;
}
