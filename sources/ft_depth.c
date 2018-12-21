/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:51:17 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/03 10:51:22 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_depth(t_map *map)
{
	int min;
	int max;
	int x;
	int y;
	int z;

	min = 100;
	max = -100;
	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			z = map->z[y][x];
			if (z < min)
				min = z;
			if (z > max)
				max = z;
		}
	}
	map->depth_min = min;
	map->depth_max = max;
}
