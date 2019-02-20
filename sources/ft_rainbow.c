/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:17:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/20 14:17:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

static void	ft_power_up(unsigned char *const col, int *const mor)
{
	if ((*mor + *col) > UCHAR_MAX)
	{
		*mor -= (UCHAR_MAX - *col);
		*col = UCHAR_MAX;
	}
	else
	{
		*col += *mor;
		*mor = 0;
	}
}

static void	ft_power_down(unsigned char *const col, int *const mor)
{
	if ((*col - *mor) < 0)
	{
		*mor -= *col;
		*col = 0;
	}
	else
	{
		*col -= *mor;
		*mor = 0;
	}
}

int		ft_rainbow(int morph, int base_clr)
{
	unsigned char *color;

	color = (unsigned char *)&base_clr;
	morph %= 1536;
	while (morph)
	{
		if (*(color + 2) == UCHAR_MAX && *color)
			ft_power_down(color, &morph);
		else if (*(color + 2) == UCHAR_MAX && *(color + 1) < UCHAR_MAX)
			ft_power_up((color + 1), &morph);
		else if (*(color + 1) == UCHAR_MAX && *(color + 2))
			ft_power_down((color + 2), &morph);
		else if (*(color + 1) == UCHAR_MAX && *color < UCHAR_MAX)
			ft_power_up(color, &morph);
		else if (*color == UCHAR_MAX && *(color + 1))
			ft_power_down((color + 1), &morph);
		else if (*color == UCHAR_MAX && *(color + 2) < UCHAR_MAX)
			ft_power_up((color + 2), &morph);
	}
	return (base_clr);
}
