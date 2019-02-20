/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wizard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 10:53:17 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 10:53:20 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_img	*ft_new_img(t_map *map)
{
	t_img *img;

	if (!(img = ft_memalloc(sizeof(t_img))))
		ft_error("couldn't allocate memory");
	if (!(img->img = mlx_new_image(map->mlx, W_WIDTH, W_HEIGHT)))
		ft_error("couldn't create image");
	img->img_ptr = mlx_get_data_addr(img->img, &img->bit_per_pix,
		&img->size_line, &img->endian);
	img->bit_per_pix = 4;
	return (img);
}

static void		ft_build_map(t_map *map, char *file_name, int colour)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, W_WIDTH, W_HEIGHT, file_name);
	map->in.size = (W_WIDTH / map->x) >> 1;
	map->in.sidex = W_WIDTH >> 1;
	map->in.sidey = W_HEIGHT >> 1;
	map->in.lean = 0;
	map->in.rate = 0;
	map->in.round = 0;
	map->colour = colour;
	map->vec_clr = map->colour;
	map->img = ft_new_img(map);
}

static int		ft_base_clr(char *clr)
{
	if (clr)
	{
		ft_striter(clr, &ft_toupper);
		if (!ft_strcmp(clr, "GREEN"))
			return (0x00FF00);
		if (!ft_strcmp(clr, "RED"))
			return (0xFF0000);
		if (!ft_strcmp(clr, "BLUE"))
			return (0x0000FF);
		if (!ft_strcmp(clr, "YELLOW"))
			return (0xFFFF00);
		if (!ft_strcmp(clr, "AZURE"))
			return (0x00FFFF);
		if (!ft_strcmp(clr, "PURPLE"))
			return (0xFF00FF);
	}
	return (0xFFFFFF);
}

void			ft_wizard(char *file_name, char *base_colour)
{
	t_map	*map;

	map = ft_read_file(file_name);
	ft_build_map(map, file_name, ft_base_clr(base_colour));
	mlx_hook(map->window, 17, 0, ft_red_cross, map);
	mlx_hook(map->window, 2, 0, ft_key_down, map);
	mlx_hook(map->window, 3, 0, ft_key_up, map);
	mlx_hook(map->window, 4, 0, hook_mousedown, &map->in);
	mlx_hook(map->window, 5, 0, hook_mouseup, &map->in);
	mlx_hook(map->window, 6, 0, hook_mousemove, &map->in);
	mlx_loop_hook(map->mlx, ft_loop, map);
	mlx_loop(map->mlx);
}
