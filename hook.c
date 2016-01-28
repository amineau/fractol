/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/01/28 10:05:32 by amineau          ###   ########.fr       */
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
	display_mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		e->iter_max++;
	if (keycode == 78 && e->iter_max > 1)
		e->iter_max--;
	if (keycode == 125)
	{
		e->y1 += 50 / e->zoom;
		e->y2 += 50 / e->zoom;
	}
	if (keycode == 126)
	{
		e->y1 -= 50 / e->zoom;
		e->y2 -= 50 / e->zoom;
	}
	if (keycode == 123)
	{
		e->x1 -= 50 / e->zoom;
		e->x2 -= 50 / e->zoom;
	}
	if (keycode == 124)
	{
		e->x1 += 50 / e->zoom;
		e->x2 += 50 / e->zoom;
	}

		if (e)
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
	printf("button : %d || x : %d || y : %d\n", button, x, y);
	if (button == 5 || button == 6)
	{
		printf("1:e->x1 : %f\n",e->x1);
		e->x1 += 0.1 * ((e->pos_x * (e->x2 - e->x1) / e->image_x) - e->x1);
		e->y1 += 0.1 * ((e->pos_y * (e->y2 - e->y1) / e->image_y) - e->y1);
		printf("2:e->x1 : %f\n",e->x1);
		e->zoom *= 1.1;
	}
		if (button == 4 || button == 7)
		{
			e->zoom /= 1.1;
		}
			image(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	image(e);
	return (0);
}
