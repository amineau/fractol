/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:29:59 by amineau           #+#    #+#             */
/*   Updated: 2016/02/22 17:16:12 by amineau          ###   ########.fr       */
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

int		julia(t_env *e)
{
	e->c_r = e->v_r;
	e->c_i = e->v_i;
	e->z_r = (e->x * (e->x2 - e->x1) / e->image_x) + e->x1;
	e->z_i = (e->y * (e->y2 - e->y1) / e->image_y) + e->y1;
	return (0);
}

void	display_julia(t_env *e)
{
	int		i;
	double	tmp;

	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			i = julia(e);
			while (i++ < e->im && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r) - (e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
			}
			if (i == e->im)
				display(e, 0, 0, 0);
			else
				display(e, 30 - i * 20 / e->im, 20, i * 255 / e->im);
		}
	}
}

void	boucle_karpet(t_env *e, t_kar *k)
{
	int		xc;
	int		xc2;
	int		yc;
	int		yc2;

	k->cote /= 3;
	xc = (int)(k->x + k->cote);
	xc2 = (int)(k->x + 2 * k->cote);
	yc = (int)(k->y + k->cote);
	yc2 = (int)(k->y + 2 * k->cote);
	e->x = ((int)k->x > 0) ? (int)k->x - 1 : -1;
	while (++e->x < e->x2 && e->x < k->x + k->cote * 3)
	{
		e->y = ((int)k->y > 0) ? (int)k->y - 1 : -1;
		while (++e->y < e->y2 && e->y < k->y + k->cote * 3)
		{
			if ((k->iter == e->im && (e->x < k->x || e->x > k->x + k->cote * 3
			|| e->y < k->y || e->y > k->y + k->cote * 3)) ||
			((e->x > xc && e->x < xc2) && (e->y > yc && e->y < yc2)))
				display(e, 0, 0, 0);
			else if (k->iter == e->im)
				display(e, e->b, e->g, e->r);
		}
	}
}

void	karpet(t_env *e, t_kar k)
{
	//	printf("k.x + k.cote : %d || k.x : %f < %f\n",(int)(k.x + k.cote), k.x, e->x2);
	if (k.iter > 0 && k.x + k.cote > 0.0 && k.x <= e->x2 &&
			k.y + k.cote > 0.0 && k.y <= e->y2 && k.cote > 3.0)
	{
		boucle_karpet(e, &k);
		k.iter--;
		karpet(e, k);
		k.y += k.cote;
		karpet(e, k);
		k.y += k.cote;
		karpet(e, k);
		k.x += k.cote;
		k.y -= 2 * k.cote;
		karpet(e, k);
		k.y += 2 * k.cote;
		karpet(e, k);
		k.x += k.cote;
		k.y -= 2 * k.cote;
		karpet(e, k);
		k.y += k.cote;
		karpet(e, k);
		k.y += k.cote;
		karpet(e, k);
	}
}

void	display_karpet(t_env *e)
{
	t_kar	k;

	k.x = e->z_r;
	k.y = e->z_i;
	k.cote = e->c_r;
	k.iter = e->im;
	karpet(e, k);
}
