/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:38:42 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:39:52 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_env *e)
{
	e->c_r = (e->x * (e->x2 - e->x1) / e->image_x) + e->x1;
	e->c_i = (e->y * (e->y2 - e->y1) / e->image_y) + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	return (0);
}

void	display_mandelbrot(t_env *e)
{
	int		i;
	double	tmp;

	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			i = mandelbrot(e);
			while (i++ < e->im && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
			}
			if (i == e->im)
				display(e, 0, 0, 0);
			else
				display(e, i * 255 / e->im - e->b - 255, i * 255 /
						e->im - e->g - 255, i * 255 / e->im - e->r - 255);
		}
	}
}
