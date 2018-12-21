/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:26:57 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 09:41:14 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	*(int *)(img->img_ptr + ((x + (y << 11)) << 2)) = color;
}

void		ft_draw_line(t_img *img, t_vector v1, t_vector v2)
{
	t_draw dr;

	dr.delta_x = ABS(((int)v2.x - (int)v1.x));
	dr.delta_y = ABS(((int)v2.y - (int)v1.y));
	dr.sign_x = (int)v1.x < (int)v2.x ? 1 : -1;
	dr.sign_y = (int)v1.y < (int)v2.y ? 1 : -1;
	dr.border1 = dr.delta_x - dr.delta_y;
	while ((int)v1.x != (int)v2.x || (int)v1.y != (int)v2.y)
	{
		if (v2.clr && v2.clr--)
			v1.clr = ft_rainbow(1, v1.clr);
		ft_img_set_pixel(img, (int)v1.x, (int)v1.y, v1.clr);
		dr.border2 = dr.border1 << 1;
		if (dr.border2 > -dr.delta_y)
		{
			dr.border1 -= dr.delta_y;
			v1.x += dr.sign_x;
		}
		if (dr.border2 < dr.delta_x)
		{
			dr.border1 += dr.delta_x;
			v1.y += dr.sign_y;
		}
	}
}
