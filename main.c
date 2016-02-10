/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:18:52 by amineau           #+#    #+#             */
/*   Updated: 2016/02/10 18:57:10 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	initialize_mandel(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->image_x = (e->x2 - e->x1) * 300;
	e->image_y = (e->y2 - e->y1) * 300;
	e->iter_max = 50;
}

void	initialize_julia(t_env *e)
{
	e->x1 = -1;
	e->x2 = 1;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->v_r = 0.285;
	e->v_i = 0.01;
	e->image_x = (e->x2 - e->x1) * 300;
	e->image_y = (e->y2 - e->y1) * 300;
	e->iter_max = 75;
	e->block = 0;
}

void	initialize_julia(t_env *e)
{
	e->x1 = 0;
	e->x2 = 300;
	e->y1 = 0;
	e->y2 = 300;
	e->v_r = -0.00508;
	e->v_i = 0.33136;
	e->image_x = (e->x2 - e->x1);
	e->image_y = (e->y2 - e->y1);
	e->iter_max = 0.1;
	e->block = 0;
}

void	initialize(t_env *e, char *str)
{
	e->fract = str;
	if (ft_strcmp(e->fract, "mandelbrot") == 0)
		   	initialize_mandel(e);
	if (ft_strcmp(e->fract,"julia") == 0)
		   	initialize_julia(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->image_x, e->image_y, e->fract);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		initialize(&e, av[1]);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion_notify, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse_press, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key_press, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putendl("error : invalid number of arguments");
	return (0);
}
