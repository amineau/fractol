/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:51:42 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:52:45 by amineau          ###   ########.fr       */
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
