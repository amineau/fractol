/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:21:31 by amineau           #+#    #+#             */
/*   Updated: 2016/01/26 09:36:15 by amineau          ###   ########.fr       */
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
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	float	image_x;
	float	image_y;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		iter_max;
	int		f;
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
