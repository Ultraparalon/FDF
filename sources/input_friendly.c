/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_friendly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:33:57 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/21 13:33:59 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			hook_mousedown(int button, int x, int y, t_input *in)
{
	(void)x;
	(void)y;
	in->key |= (1 << button);
	if (button == 4)
		in->size++;
	else if (button == 5 && in->size > 1)
		in->size--;
	return (0);
}

int			hook_mouseup(int button, int x, int y, t_input *in)
{
	(void)x;
	(void)y;
	in->key ^= (1 << button);
	return (0);
}

int			hook_mousemove(int x, int y, t_input *in)
{
	static int	lx;
	static int	ly;

	if (in->key & (1 << 2))
	{
		in->lean += (ly - y) / 200.0f;
		in->rate -= (lx - x) / 200.0f;
	}
	else if (in->key & (1 << 1))
	{
		in->sidex -= (lx - x);
		in->sidey -= (ly - y);
	}
	lx = x;
	ly = y;
	return (0);
}

int			ft_red_cross(void)
{
	exit(0);
	return (0);
}
