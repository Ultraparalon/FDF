/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:51:04 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/23 10:51:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_help(t_map *map)
{
	if (map->in.key & (1 << 3))
	{
		mlx_string_put(map->mlx, map->window, 5, 5, 0xFFFFFF, "'Esc' exit");
		mlx_string_put(map->mlx, map->window, 5, 30, 0xFFFFFF, "'C' colour");
		mlx_string_put(map->mlx, map->window, 5, 60, 0xFFFFFF, " ^");
		mlx_string_put(map->mlx, map->window, 5, 70, 0xFFFFFF, "< > move");
		mlx_string_put(map->mlx, map->window, 5, 100, 0xFFFFFF, "7 8 9");
		mlx_string_put(map->mlx, map->window, 5, 120, 0xFFFFFF, "4num6");
		mlx_string_put(map->mlx, map->window, 5, 140, 0xFFFFFF, "  2  rotate");
		mlx_string_put(map->mlx, map->window, 5, 170, 0xFFFFFF, "'+-' zoom");
	}
	else
		mlx_string_put(map->mlx, map->window, 5, 5, 0xFFFFFF, "Press (H)elp");
}

int			ft_loop(t_map *map)
{
	ft_bzero(map->img->img_ptr, W_WIDTH * W_HEIGHT * map->img->bit_per_pix);
	map->colour = ft_rainbow(1, map->colour);
	ft_create_map(map);
	if (map->in.key & (1 << 16))
		map->in.size++;
	if (map->in.key & (1 << 17) && map->in.size > 1)		
		map->in.size--;
	if (map->in.key & (1 << 6))
		map->in.sidex -= 10;
	if (map->in.key & (1 << 7))
		map->in.sidex += 10;
	if (map->in.key & (1 << 8))
		map->in.sidey -= 10;
	if (map->in.key & (1 << 9))
		map->in.sidey += 10;
	if (map->in.key & (1 << 10))
		map->in.round -= ROT;
	if (map->in.key & (1 << 11))
		map->in.round += ROT;
	if (map->in.key & (1 << 12))
		map->in.rate += ROT;
	if (map->in.key & (1 << 13))
		map->in.rate -= ROT;
	if (map->in.key & (1 << 14))
		map->in.lean += ROT;
	if (map->in.key & (1 << 15))
		map->in.lean -= ROT;
	ft_help(map);
	return (0);
}

int			ft_key_down(int key, t_map *map)
{
	if (key == 4) // help
		map->in.key ^= (1 << 3);
	else if (key == 69 || key == 24) // size +
		map->in.key |= (1 << 16);
	else if ((key == 78 || key == 27)) // size -
		map->in.key |= (1 << 17);
	else if (key == 124) // move left
		map->in.key |= (1 << 6);
	else if (key == 123) // move right
		map->in.key |= (1 << 7);
	else if (key == 125) // move up
		map->in.key |= (1 << 8);
	else if (key == 126) // move down
		map->in.key |= (1 << 9);
	else if (key == 89) // rotate z
		map->in.key |= (1 << 10);
	else if (key == 92) // rotate z
		map->in.key |= (1 << 11);
	else if (key == 88) // rotate x
		map->in.key |= (1 << 12);
	else if (key == 86) // rotate x
		map->in.key |= (1 << 13);
	else if (key == 84) // rotate y
		map->in.key |= (1 << 14);
	else if (key == 91) // rotate y
		map->in.key |= (1 << 15);
	else if (key == 53)
		exit(0);
	else if (key == 8)
		map->colour = ft_rainbow(255, map->colour);
	return (0);
}

int			ft_key_up(int key, t_map *map)
{
	if (key == 69 || key == 24)
		map->in.key ^= (1 << 16);
	else if ((key == 78 || key == 27)) // size -
		map->in.key ^= (1 << 17);
	else if (key == 124) // move left
		map->in.key ^= (1 << 6);
	else if (key == 123) // move right
		map->in.key ^= (1 << 7);
	else if (key == 125) // move up
		map->in.key ^= (1 << 8);
	else if (key == 126) // move down
		map->in.key ^= (1 << 9);
	else if (key == 89) // rotate z
		map->in.key ^= (1 << 10);
	else if (key == 92) // rotate z
		map->in.key ^= (1 << 11);
	else if (key == 88) // rotate x
		map->in.key ^= (1 << 12);
	else if (key == 86) // rotate x
		map->in.key ^= (1 << 13);
	else if (key == 84) // rotate y
		map->in.key ^= (1 << 14);
	else if (key == 91) // rotate y
		map->in.key ^= (1 << 15);
	return (0);
}
