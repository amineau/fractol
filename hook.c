/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/02/22 14:34:44 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
void	image(t_env *e)
{
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->image_x, e->image_y);
	e->img_addr = mlx_get_data_addr(e->img,
			&e->bits_pix, &e->size_line, &e->end);
	if (ft_strcmp(e->fract, "mandelbrot") == 0)
		display_mandelbrot(e);
	if (ft_strcmp(e->fract, "julia") == 0)
		display_julia(e);
	if (ft_strcmp(e->fract, "karpet") == 0)
		display_karpet(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		key_press(int keycode, t_env *e)
{
	double	dif_x;
	double	dif_y;

	if (keycode == 53)
		exit(0);
	e->iter_max += (keycode == 69) ? 1 : 0;
	e->iter_max -= (keycode == 78 && e->iter_max > 1) ? 1 : 0;
	if (ft_strcmp(e->fract, "karpet") == 0)
	{
		e->z_i -= (keycode == 125) ? e->image_y / 20 : 0;
		e->z_i += (keycode == 126) ? e->image_y / 20 : 0;
		e->z_r -= (keycode == 124) ? e->image_x / 20 : 0;
		e->z_r += (keycode == 123) ? e->image_x / 20 : 0;
	}
	else
	{
		dif_x = e->x2 - e->x1;
		dif_y = e->y2 - e->y1;
		e->y1 += (keycode == 125) ? dif_y / 20 : 0;
		e->y1 -= (keycode == 126) ? dif_y / 20 : 0;
		e->x1 -= (keycode == 123) ? dif_x / 20 : 0;
		e->x1 += (keycode == 124) ? dif_x / 20 : 0;
		e->x2 = e->x1 + dif_x;
		e->y2 = e->y1 + dif_y;
	}
	if (keycode == 49)
		e->block = (e->block == 0) ? 1 : 0;
	image(e);
	return (0);
}

int		motion_notify(int x, int y, t_env *e)
{
	if ((ft_strcmp(e->fract, "julia") == 0) && e->block == 1)
	{
		e->v_r = (double)(x - 400) / 500;
		e->v_i = (double)(y - 300) / 500;
		image(e);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	double	k_x;
	double	k_y;

	if (ft_strcmp(e->fract, "karpet") == 0)
	{
		if (button == 5 || button == 6)
		{
			e->c_r *= 1.1;
			e->z_r += (e->z_r - x) * 0.1;
			e->z_i += (e->z_i - y) * 0.1;
		}
		if (button == 4 || button == 7)
		{
			e->c_r /= 1.1;
			e->z_r -= (e->z_r - x) * 0.1;
			e->z_i -= (e->z_i - y) * 0.1;
		}
	}
	else
	{
	k_x = (x * (e->x2 - e->x1) / e->image_x) + e->x1;
	k_y = (y * (e->y2 - e->y1) / e->image_y) + e->y1;
	if (button == 5 || button == 6)
	{
		e->x2 = k_x + (e->x2 - k_x) / 1.1;
		e->y2 = k_y + (e->y2 - k_y) / 1.1;
		e->x1 = k_x + (e->x1 - k_x) / 1.1;
		e->y1 = k_y + (e->y1 - k_y) / 1.1;
	}
	if (button == 4 || button == 7)
	{
		e->x2 = k_x + (e->x2 - k_x) * 1.1;
		e->y2 = k_y + (e->y2 - k_y) * 1.1;
		e->x1 = k_x + (e->x1 - k_x) * 1.1;
		e->y1 = k_y + (e->y1 - k_y) * 1.1;
	}
	}
	image(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	image(e);
	return (0);
}
