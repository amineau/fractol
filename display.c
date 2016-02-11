/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:29:59 by amineau           #+#    #+#             */
/*   Updated: 2016/02/11 18:08:20 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	display(t_env *e, int blue, int green, int red)
{
	e->img_addr[e->y * e->size_line + e->x * e->bits_pix / 8] = blue;
	e->img_addr[e->y * e->size_line + e->x * e->bits_pix / 8 + 1] = green;
	e->img_addr[e->y * e->size_line + e->x * e->bits_pix / 8 + 2] = red;

}

void	display_mandelbrot(t_env *e)
{
	int		i;
	double	tmp;

	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = (e->x * (e->x2 - e->x1) / e->image_x) + e->x1;
			e->c_i = (e->y * (e->y2 - e->y1) / e->image_y) + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			i = 0;
			while (i < e->iter_max && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
				i++;
			}
			if (i == e->iter_max)
				display(e, 0, 0, 0);
			else
				display(e, i * 255 / e->iter_max, i * 255 / e->iter_max, i * 255 / e->iter_max);
			e->y++;
		}
		e->x++;
	}
}

void	display_julia(t_env *e)
{
	int		i;
	double	tmp;

	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = e->v_r;
			e->c_i = e->v_i;
			e->z_r = (e->x * (e->x2 - e->x1) / e->image_x) + e->x1;
			e->z_i = (e->y * (e->y2 - e->y1) / e->image_y) + e->y1;
			i = 0;
			while (i < e->iter_max && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
				i++;
			}
			if (i == e->iter_max)
				display(e, 0, 0, 0);
			else
				display(e, 30 - i * 20 / e->iter_max, 20, i * 255 / e->iter_max);
			e->y++;
		}
		e->x++;
	}
}

void	display_newton(t_env *e)
{
	int		i;
	double	tmp;
	double	appro;

	appro = 0.1;
	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = e->v_r;
			e->c_i = e->v_i;
			e->z_r = (e->x * (e->x2 - e->x1) / e->image_x) + e->x1;
			e->z_i = (e->y * (e->y2 - e->y1) / e->image_y) + e->y1;
			i = 0;
			while (i < e->iter_max)
			{
				tmp = e->z_r;
				e->z_r = e->z_r * (e->z_r * e->z_r - e->c_r * e->c_r + e->c_i * e->c_i - 3 * e->z_i * e->z_i - 3 / 4) + e->c_i * (2 * e->c_r * e->z_i - e->c_i) + e->c_r * e->c_r - 1 / 4;
				e->z_i = e->z_i * (3 * tmp * tmp - e->c_r * e->c_r - e->z_i * e->z_i + e->c_i * e->c_i - 3 / 4) + e->c_i * e->c_r * (2 - 2 * tmp);
				if (fabs(e->z_r - 1) <= appro && fabs(e->z_i) <= appro)
				{	
					display(e, 255, 0, 0);
					break;
				}
				else if (fabs(e->z_r - e->c_r + 1 / 2) <= appro && fabs(e->z_i - e->c_i) <= appro)
				{	
					display(e, 0, 255, 0);
					break;
				}
				else if (fabs(e->z_r + e->c_r + 1 / 2) <= appro && fabs(e->z_i + e->c_i) <= appro)
				{			
					display(e, 0, 0, 255);
					break;
				}
				i++;
			}
			if (i == e->iter_max)
				display(e, 0, 0, 0);
			e->y++;
		}
		e->x++;
	}
}
