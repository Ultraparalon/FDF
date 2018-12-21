/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:26:47 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/23 16:26:49 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	vec_swap(t_vector *vec1, t_vector *vec2)
{
	vec2->bz = vec1->clr;
	vec1->clr = vec2->clr;
	vec2->clr = vec2->bz;
}

static void	ft_clr(t_vector *vec1, t_vector *vec2, int base_clr)
{
	vec1->clr = base_clr;
	if (!vec1->bz && !vec2->bz)
	{
		vec2->clr = 0;
	}
	else if (vec1->bz > vec2->bz)
	{
		vec2->clr = ABS((vec1->bz - vec2->bz)) * COL;
		vec1->clr = ft_rainbow(ABS(vec2->bz * COL), vec1->clr);
	}
	else if (vec2->bz > vec1->bz)
	{
		vec2->clr = ABS((vec2->bz - vec1->bz)) * COL;
		vec1->clr = ft_rainbow(ABS(vec1->bz * COL), vec1->clr);
	}
	else if (vec1->bz == vec2->bz)
	{
		vec1->clr = ft_rainbow(ABS(vec1->bz * COL), vec1->clr);
	}
}

static int	ft_check_line(t_vector *vec1, t_vector *vec2)
{
	if ((vec1->y < 0 && vec2->y < 0)
		|| (vec1->y > W_HEIGHT && vec2->y > W_HEIGHT)
		|| (vec1->x < 0 && vec2->x < 0)
		|| (vec1->x > W_WIDTH && vec2->x > W_WIDTH))
		return (0);
	return (1);
}

static void	ft_draw(t_vector *vec1, t_vector *vec2, t_map *map)
{
	if (ft_check_line(vec1, vec2))
	{
		ft_clr(vec1, vec2, map->colour);
		if (vec1->bz > vec2->bz)
		{
			vec_swap(vec1, vec2);
			ft_draw_line(map->img, *vec2, *vec1);
		}
		else
			ft_draw_line(map->img, *vec1, *vec2);
	}
}

void		ft_create_map(t_map *map)
{
	int			y;
	int			x;
	t_vector	vec1;
	t_vector	vec2;

	x = -1;
	while (++x < map->x)
	{
		y = -1;
		while (++y < map->y)
		{
			vec1 = ft_vector(map->z[y][x], x, y, map);
			if (x + 1 < map->x)
			{
				vec2 = ft_vector(map->z[y][x + 1], x + 1, y, map);
				ft_draw(&vec1, &vec2, map);
			}
			if (y + 1 < map->y)
			{
				vec2 = ft_vector(map->z[y + 1][x], x, y + 1, map);
				ft_draw(&vec1, &vec2, map);
			}
		}
	}
	mlx_put_image_to_window(map->mlx, map->window, map->img->img, 0, 0);
}
