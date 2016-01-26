/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:29:59 by amineau           #+#    #+#             */
/*   Updated: 2016/01/26 09:41:10 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
void	display_mandelbrot(t_env *e)
{
	int	x;
	int	y;
	int i;
	int	tmp;

	x = 1;
	while (x < e->image_x)
	{
		y = 1;
		while (y < e->image_y)
		{
			e->c_r = x / e->zoom + e->x1;
			e->c_i = y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			i = 0;
			while (i < e->iter_max && e->z_r * e->z_r + e->z_i * e->z_i < e->f)
			{
				tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
				i++;
			}
		//	printf("i : %d || c_r : %f || zi : %f\n", i, e->c_r, e->z_i);
			if (i == e->iter_max)
			{
				e->img_addr[y * e->size_line + x * e->bits_pix / 8] = 255;
				e->img_addr[y * e->size_line + x * e->bits_pix / 8 + 1] = 255;
				e->img_addr[y * e->size_line + x * e->bits_pix / 8 + 2] = 255;
			}
			y++;
		}
		x++;
	}
}
