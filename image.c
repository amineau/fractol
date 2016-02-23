/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:51:42 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 14:55:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image(t_env *e)
{
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->image_x, e->image_y);
	e->img_addr = mlx_get_data_addr(e->img,
			&e->bits_pix, &e->size_line, &e->end);
	if (ft_strcasecmp(e->fract, "mandelbrot") == 0)
		display_mandelbrot(e);
	if (ft_strcasecmp(e->fract, "julia") == 0)
		display_julia(e);
	if (ft_strcasecmp(e->fract, "carpet") == 0)
		display_carpet(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		expose_hook(t_env *e)
{
	image(e);
	return (0);
}

void	move(t_env *e, int keycode)
{
	double	dif_x;
	double	dif_y;

	if (ft_strcasecmp(e->fract, "carpet") == 0)
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
}
