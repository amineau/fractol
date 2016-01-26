/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/01/26 09:41:12 by amineau          ###   ########.fr       */
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
	if (keycode == 125 && e->f > 1)
		e->f--;
	if (keycode == 126)
		e->f++;
	if (e)
		printf("keycode : %d\n", keycode);
	image(e);
	return (0);
}

int		motion_notify(int x, int y, t_env *e)
{
	if (e || x || y)
		;
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	if (button || x || e || y)
		printf("button : %d\n", button);
	if (button == 5)
		e->zoom *= 1.1;
	if (button == 4)
		e->zoom /= 1.1;
	image(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	image(e);
	return (0);
}
