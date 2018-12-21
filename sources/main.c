/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:04:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 10:12:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_wizard(argv[1], NULL);
	else if (argc == 3)
		ft_wizard(argv[1], argv[2]);
	else
	{
		ft_putendl("usage: fdf map_name colour_type");
		ft_putendl("       colours: [GREEN] [YELLOW] [RED]");
		ft_putendl("                [BLUE] [AZURE] [PURPLE]");
	}
	return (0);
}
