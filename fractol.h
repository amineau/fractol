/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:21:31 by amineau           #+#    #+#             */
/*   Updated: 2016/01/27 14:51:30 by amineau          ###   ########.fr       */
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
	double	zoom;
	double	image_x;
	double	image_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		iter_max;
	int		pos_x;
	int		pos_y;
  	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_pix;
	int		size_line;
	int		end;
}				        t_env;

int		key_press(int keycode, t_env *e);
int		motion_notify(int x, int y, t_env *e);
int		mouse_press(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e);
void	display_mandelbrot(t_env *e);

#endif
