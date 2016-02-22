/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:21:31 by amineau           #+#    #+#             */
/*   Updated: 2016/02/22 14:34:46 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_env
{
	char	*fract;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	image_x;
	double	image_y;
	double	c_r;
	double	c_i;
	double	v_r;
	double	v_i;
	double	z_r;
	double	z_i;
	int		x;
	int		y;
	int		iter_max;
	int		block;
	int		b;
	int		g;
	int		r;
  	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_pix;
	int		size_line;
	int		end;
}				t_env;

typedef struct	s_karpet
{
	double	x;
	double	y;
	double	cote;
	int		iter;
}				t_kar;

int		key_press(int keycode, t_env *e);
int		motion_notify(int x, int y, t_env *e);
int		mouse_press(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e);
void	display_mandelbrot(t_env *e);
void	display_julia(t_env *e);
void	display_karpet(t_env *e);

#endif
