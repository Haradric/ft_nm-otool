/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <mbraslav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:29:52 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/26 15:30:10 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*get_mode_(void)
{
	static int mode = 0;

	return (&mode);
}

int			get_mode(void)
{
	return (*get_mode_());
}

void		set_mode(int mode)
{
	*get_mode_() = mode;
}
