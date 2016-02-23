/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:40:04 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:43:45 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
