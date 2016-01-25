/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:37:06 by amineau           #+#    #+#             */
/*   Updated: 2015/11/29 10:23:18 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int nb, int pow)
{
	int i;

	i = 1;
	if (pow == 0)
		nb = 1;
	else
	{
		while (i != pow)
		{
			nb *= 10;
			i++;
		}
	}
	return (nb);
}

static char	*ft_decomp(int nbr, int pow, int neg)
{
	int		j;
	int		i;
	int		digit;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (pow + neg + 2))))
		return (NULL);
	if (neg == 1)
		str[i++] = '-';
	j = pow;
	while (i <= pow + neg)
	{
		digit = nbr / ft_power(10, j);
		nbr = nbr % ft_power(10, j);
		str[i] = digit + 48;
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int c)
{
	int		neg;
	int		pow;
	int		tmp;

	neg = 0;
	pow = 0;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	if (c < 0)
	{
		neg = 1;
		c = -c;
	}
	tmp = c;
	while (tmp >= 10)
	{
		tmp /= 10;
		pow++;
	}
	return (ft_decomp(c, pow, neg));
}
