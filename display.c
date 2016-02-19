/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:29:59 by amineau           #+#    #+#             */
/*   Updated: 2016/02/19 23:23:46 by amineau          ###   ########.fr       */
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

void	karpet(t_env *e, double x, double y, int iter, int cote)
{
	if (iter > 0)
	{
		e->x = 0;
		while (e->x < e->x2)
		{
			e->y = 0;
			while (e->y < e->y2)
			{
				if ((iter == e->iter_max && (e->x < x || e->x > x + cote || e->y < y || e->y > y + cote)) || ((e->x > (int)(x + cote / 3) && e->x < (int)(x + 2 * cote / 3)) && (e->y > (int)(y + cote / 3) && e->y < (int)(y + 2 * cote / 3)))) 
					display(e, 0, 0, 0);
				else if (iter == e->iter_max)
					display(e, 0, 255, 255);
				e->y++;
			}
			e->x++;
		}
		karpet(e, x, y, iter - 1, cote / 3);
		karpet(e, x, y + cote / 3, iter - 1, cote / 3);
		karpet(e, x, y + 2 * cote / 3, iter - 1, cote / 3);
		karpet(e, x + cote / 3, y, iter - 1, cote / 3);
		karpet(e, x + cote / 3, y + cote / 3, iter - 1, cote / 3);
		karpet(e, x + cote / 3, y + 2 * cote / 3, iter - 1, cote / 3);
		karpet(e, x + 2 * cote / 3, y, iter - 1, cote / 3);
		karpet(e, x + 2 * cote / 3, y + cote / 3, iter - 1, cote / 3);
		karpet(e, x + 2 * cote / 3, y + 2 * cote / 3, iter - 1, cote / 3);
	}
}

void	display_karpet(t_env *e)
{	
	t_kar	k;

	k.x = e->image_x / 4;
	k.y = e->image_y / 4;
	k.cote = e->image_x / 2;
	k.iter = e->iter_max;
	karpet(e, k.x, k.y, k.iter, k.cote);
}

void	display_newton(t_env *e)
{
	int		i;
	double	tmp;
	double	appro;
	double	xx;
	double	yy;

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
			while (i < e->iter_max )
			{
				tmp = e->z_r;
				xx = e->z_r * e->z_r;
				yy = e->z_i * e->z_i;
			//	e->z_r = (2 * e->z_r * (xx - 2 * yy) - 4 * yy + 1) / (9 * (xx * xx - 2 * xx * yy + yy * yy));
			//	e->z_i = (e->z_i * ( 2 * tmp + xx - yy)) / (9 * (xx * xx - 2 * xx * yy + yy * yy));
			//	e->z_r = e->z_r * (e->z_r * e->z_r - e->c_r * e->c_r + e->c_i * e->c_i - 3 * e->z_i * e->z_i - 3 / 4) + e->c_r * (e->c_r + 2 * e->c_i *e->z_i) - e->c_i * e->c_i - 1 / 4;
			//	e->z_i = e->z_i * (3 * tmp * tmp - e->c_r * e->c_r - e->z_i * e->z_i + e->c_i * e->c_i - 3 / 4) + e->c_i * e->c_r * (2 - 2 * tmp);
			e->z_r = xx * e->z_r - 3 * e->z_r * yy - 1;
			e->z_i = yy * e->z_i - 3 * xx * e->z_i;
				if (e->x == 10 && e->y == 10)
				printf("z_r : %f || z_i : %f\n", e->z_r, e->z_i);
				
				if (fabs(e->z_r - 1) <= appro && fabs(e->z_i) <= appro)
				{	
					display(e, 255, 0, 0);
		//			printf("i : %d || z_r : %f\n", i, e->z_r);
					break;
				}
				else if (fabs(e->z_r + 1 / 2) <= appro && fabs(e->z_i + sqrt(3) / 2) <= appro)
				{	
					display(e, 0, 255, 0);
					break;
				}
				else if (fabs(e->z_r + 1 / 2) <= appro && fabs(e->z_i - sqrt(3) / 2) <= appro)
				{	
					display(e, 0, 0, 255);
					break;
				}

				/*if (fabs(e->z_r - 1) <= appro && fabs(e->z_i) <= appro)
				{	
					display(e, 255, 0, 0);
		//			printf("i : %d || z_r : %f\n", i, e->z_r);
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
				}*/
				i++;
			}
			if (i == e->iter_max)
				display(e, 0, 0, 0);
		//	if (e->x % 100 == 0 && e->y % 100 == 0)
		//		printf("z_r : %f || z_i : %f\n", e->z_r, e->z_i);
			e->y++;
		}
		e->x++;
	}
}
