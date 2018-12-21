/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:14:09 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/03 13:14:11 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		ft_rotate_vector(t_vector *vec, t_map *map)
{
	double		x;
	double		y;
	double		z;

	x = vec->x;
	y = vec->y;
	z = vec->z;
	vec->y = cos(map->in.rate) * x + sin(map->in.rate) * z;
	vec->z = -sin(map->in.rate) * x + cos(map->in.rate) * z;
	z = vec->z;
	vec->x = cos(map->in.lean) * y - sin(map->in.lean) * z;
	vec->z = sin(map->in.lean) * y + cos(map->in.lean) * z;
	x = vec->x;
	y = vec->y;
	vec->x = cos(map->in.round) * y - sin(map->in.round) * x;
	vec->y = sin(map->in.round) * y + cos(map->in.round) * x;
}

t_vector		ft_vector(int z, int x, int y, t_map *map)
{
	t_vector vec;

	vec.clr = 0;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.bz = z;
	vec.x -= (double)((map->x - 1) >> 1);
	vec.y -= (double)((map->y - 1) >> 1);
	vec.z -= (double)((map->depth_min + map->depth_max) >> 1);
	ft_rotate_vector(&vec, map);
	vec.x = vec.x * map->in.size + map->in.sidex;
	vec.y = vec.y * map->in.size + map->in.sidey;
	vec.x = (int)vec.x;
	vec.y = (int)vec.y;
	return (vec);
}
