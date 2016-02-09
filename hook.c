/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/02/09 21:46:55 by amineau          ###   ########.fr       */
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
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		key_press(int keycode, t_env *e)
{
	double	dif_x;
	double	dif_y;

	dif_x = e->x2 - e->x1;
	dif_y = e->y2 - e->y1;
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		e->iter_max++;
	if (keycode == 78 && e->iter_max > 1)
		e->iter_max--;
	if (keycode == 125)
	{
		e->y1 += dif_y / 20;
		e->y2 += dif_y / 20;
	}
	if (keycode == 126)
	{
		e->y1 -= dif_y / 20;
		e->y2 -= dif_y / 20;
	}
	if (keycode == 123)
	{
		e->x1 -= dif_x / 20;
		e->x2 -= dif_x / 20;
	}
	if (keycode == 124)
	{
		e->x1 += dif_x / 20;
		e->x2 += dif_x / 20;
	}
		printf("keycode : %d\n", keycode);
	image(e);
	return (0);
}

int		motion_notify(int x, int y, t_env *e)
{
	e->pos_x = x;
	e->pos_y = y;
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	double	k_x;
	double	k_y;
	double	dif_x;
	double	dif_y;

	if (x || y)
		;
	dif_x = e->x2 - e->x1;
	dif_y = e->y2 - e->y1;
	k_x = (e->pos_x * dif_x / e->image_x) + e->x1;
	k_y = (e->pos_y * dif_y / e->image_y) + e->y1;
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
	image(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	image(e);
	return (0);
}
