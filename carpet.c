/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:44:16 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:44:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	boucle_carpet(t_env *e, t_kar *k)
{
	double	xc;
	double	xc2;
	double	yc;
	double	yc2;

	k->cote /= 3;
	xc = k->x + (int)k->cote;
	xc2 = k->x + 2 * (int)k->cote;
	yc = k->y + (int)k->cote;
	yc2 = k->y + 2 * (int)k->cote;
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

void	carpet(t_env *e, t_kar k)
{
	if (k.iter > 0 && k.x + k.cote > 0.0 && k.x <= e->x2 &&
			k.y + k.cote > 0.0 && k.y <= e->y2 && k.cote > 3.0)
	{
		boucle_carpet(e, &k);
		k.iter--;
		carpet(e, k);
		k.y += k.cote;
		carpet(e, k);
		k.y += k.cote;
		carpet(e, k);
		k.x += k.cote;
		k.y -= 2 * k.cote;
		carpet(e, k);
		k.y += 2 * k.cote;
		carpet(e, k);
		k.x += k.cote;
		k.y -= 2 * k.cote;
		carpet(e, k);
		k.y += k.cote;
		carpet(e, k);
		k.y += k.cote;
		carpet(e, k);
	}
}

void	display_carpet(t_env *e)
{
	t_kar	k;

	k.x = e->z_r;
	k.y = e->z_i;
	k.cote = e->c_r;
	k.iter = e->im;
	carpet(e, k);
}
