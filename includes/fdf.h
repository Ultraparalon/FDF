/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:23 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 09:38:53 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define W_WIDTH 2048
# define W_HEIGHT 1300
# define ROT 0.05
# define COL 20

typedef struct	s_vector
{
	double		y;
	double		x;
	double		z;
	int			bz;
	int			clr;
}				t_vector;

typedef struct	s_img
{
	void		*img;
	char		*img_ptr;
	int			bit_per_pix;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_input
{
	int			key;
	int			size;
	int			sidex;
	int			sidey;
	double		rate;
	double		lean;
	double		round;	
}				t_input;

typedef struct	s_map
{
	int			x;
	int			y;
	int			**z;
	int			colour;
	int			vec_clr;
	int			depth_min;
	int			depth_max;
	int			help;
	void		*mlx;
	void		*window;
	t_img		*img;
	t_input		in;
}				t_map;

typedef struct	s_draw
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int			border1;
	int			border2;
}				t_draw;

void			ft_create_map(t_map *map);
t_vector		ft_vector(int z, int x, int y, t_map *map);
int				ft_loop(t_map *map);
int				ft_red_cross(void);
int				ft_key_down(int key, t_map *map);
int				ft_key_up(int key, t_map *map);
int				hook_mousedown(int button, int x, int y, t_input *in);
int				hook_mouseup(int button, int x, int y, t_input *in);
int				hook_mousemove(int x, int y, t_input *in);
int				ft_rainbow(int morph, int base_clr);
void			ft_error(char *str);
t_map			*ft_parser(t_list *file, int size);
t_map			*ft_read_file(char *file_name);
void			ft_wizard(char *file_name, char *base_colour);
void			ft_draw_line(t_img *img, t_vector v1, t_vector v2);
void			ft_depth(t_map *map);

#endif
