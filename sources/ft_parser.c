/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:33:15 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 13:33:19 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		***ft_parse_to_char(t_list *file, int size)
{
	char ***box;
	char ***retbox;

	if (!(box = (char ***)ft_memalloc(sizeof(char **) * (size + 1))))
		ft_error("couldn't allocate memory");
	retbox = box;
	while (file)
	{
		if (!(box[size - 1] = ft_strsplit((char *)file->content, ' ')))
			ft_error("couldn't allocate memory");
		size--;
		file = file->next;
	}
	return (retbox);
}

static int		ft_check_size(char ***box)
{
	int	len;
	int	cardlen;
	int size;

	len = 0;
	size = 0;
	while (box[size])
	{
		cardlen = 0;
		while (box[size][cardlen])
		{
			len++;
			cardlen++;
		}
		size++;
		if (cardlen * size != len)
			ft_error("invalid map");
	}
	return (cardlen);
}

static t_map	*ft_map_init(int size, int len)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		ft_error("couldn't allocate memory");
	map->y = size;
	map->x = len;
	return (map);
}

static t_map	*ft_parse_to_int(char ***box, int size, int len)
{
	t_map	*map;
	int		x;
	int		y;

	map = ft_map_init(size, len);
	y = -1;
	if (!(map->z = (int **)ft_memalloc(sizeof(int *) * (size + 1))))
		ft_error("couldn't allocate memory");
	while (++y < size)
	{
		x = -1;
		if (!(map->z[y] = (int *)ft_memalloc(sizeof(int) * (len + 1))))
			ft_error("couldn't allocate memory");
		while (++x < len)
		{
			map->z[y][x] = ft_atoi(box[y][x]);
		}
	}
	return (map);
}

t_map			*ft_parser(t_list *file, int size)
{
	t_map	*map;
	char	***box;
	int		len;

	box = ft_parse_to_char(file, size);
	len = ft_check_size(box);
	map = ft_parse_to_int(box, size, len);
	ft_box_destructor((void ***)box);
	ft_depth(map);
	return (map);
}
