/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:32:25 by amineau           #+#    #+#             */
/*   Updated: 2016/02/23 13:50:10 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int er)
{
	if (er == 0)
		ft_putendl("error : invalid number of arguments");
	if (er == 1)
		ft_putendl("error : invalid argument");
	ft_putendl("list of valid arguments :\nMandelbrot\nJulia\nCarpet");
	exit(0);
}
