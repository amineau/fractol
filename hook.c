/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:52:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int		key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	e->im += (keycode == 69) ? 1 : 0;
	e->im -= (keycode == 78 && e->im > 1) ? 1 : 0;
	if (keycode == 49)
		e->block = (e->block == 0) ? 1 : 0;
	if (keycode == 18)
	{
		e->b -= (e->b > 4) ? 5 : 0;
		e->g -= (e->g > 4) ? 5 : 0;
		e->r -= (e->r > 4) ? 5 : 0;
	}
	if (keycode == 19)
	{
		e->b += (e->b < 251) ? 5 : 0;
		e->g += (e->g < 251) ? 5 : 0;
		e->r += (e->r < 251) ? 5 : 0;
	}
	move(e, keycode);
	image(e);
	return (0);
}

int		motion_notify(int x, int y, t_env *e)
{
	if ((ft_strcasecmp(e->fract, "julia") == 0) && e->block == 1)
	{
		e->v_r = (double)(x - 400) / 500;
		e->v_i = (double)(y - 300) / 500;
		image(e);
	}
	else if (e->block == 1)
	{
		if (x > 0 && x < e->image_x)
			e->b = x * 255 / e->image_x;
		if (y > 0 && y < e->image_y)
			e->g = y * 255 / e->image_y;
		image(e);
	}
	return (0);
}

void	zoom(t_env *e, int x, int y, int button)
{
	double	k_x;
	double	k_y;

	k_x = (x * (e->x2 - e->x1) / e->image_x) + e->x1;
	k_y = (y * (e->y2 - e->y1) / e->image_y) + e->y1;
	if (button == 5 || button == 6)
	{
		e->x2 = k_x + (e->x2 - k_x) / 1.1;
		e->y2 = k_y + (e->y2 - k_y) / 1.1;
		e->x1 = k_x + (e->x1 - k_x) / 1.1;
		e->y1 = k_y + (e->y1 - k_y) / 1.1;
	}
	if (button == 4 || button == 7)
	{
		e->x2 = k_x + (e->x2 - k_x) * 1.1;
		e->y2 = k_y + (e->y2 - k_y) * 1.1;
		e->x1 = k_x + (e->x1 - k_x) * 1.1;
		e->y1 = k_y + (e->y1 - k_y) * 1.1;
	}
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	if (ft_strcasecmp(e->fract, "carpet") == 0)
	{
		if (button == 5 || button == 6)
		{
			e->c_r *= 1.1;
			e->z_r += (e->z_r - x) * 0.1;
			e->z_i += (e->z_i - y) * 0.1;
		}
		if (button == 4 || button == 7)
		{
			e->c_r *= 0.9;
			e->z_r -= (e->z_r - x) * 0.1;
			e->z_i -= (e->z_i - y) * 0.1;
		}
	}
	else
		zoom(e, x, y, button);
	image(e);
	return (0);
}
