/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:11:41 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 11:12:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*ft_copy(int file_desu, int *size)
{
	t_list	*ret;
	t_list	*tmp;
	char	*str;

	ret = NULL;
	while (get_next_line(file_desu, &str) > 0)
	{
		if (!(tmp = ft_lstnew((void *)str, (ft_strlen(str) + 1))))
			ft_error("couldn't allocate memory");
		ft_lstadd(&ret, tmp);
		free(str);
		(*size)++;
	}
	return (ret);
}

t_map			*ft_read_file(char *file_name)
{
	t_map	*map;
	t_list	*file;
	int		file_desu;
	int		size;

	size = 0;
	if ((file_desu = open(file_name, O_RDWR)) < 0)
		ft_error("no such file");
	file = ft_copy(file_desu, &size);
	map = ft_parser(file, size);
	ft_lstdel(&file);
	return (map);
}
