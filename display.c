/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:29:59 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:45:32 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display(t_env *e, int blue, int green, int red)
{
	e->img_addr[e->y * e->size_line + e->x * e->bits_pix / 8] = blue;
	e->img_addr[e->y * e->size_line + e->x * e->bits_pix / 8 + 1] = green;
	e->img_addr[e->y * e->size_line + e->x * e->bits_pix / 8 + 2] = red;
}
