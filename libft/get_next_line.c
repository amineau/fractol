/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:54:48 by amineau           #+#    #+#             */
/*   Updated: 2016/01/10 17:58:59 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_endline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (2);
}

static int	ft_check_rest(char **rest, char **line)
{
	char *p;

	if (*rest)
	{
		if ((p = ft_strchr(*rest, '\n')))
		{
			*line = ft_strndup(*rest, p - *rest);
			*rest = p + 1;
			return (1);
		}
		else
		{
			*line = ft_strdup(*rest);
			ft_strclr(*rest);
		}
	}
	return (0);
}

static char	*ft_trac(char *rest, char **buf)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if ((*buf)[i] == '\n')
	{
		end = i;
		if (!(rest = ft_memalloc(sizeof(char) * (ft_strlen(*buf) - i))))
			return (NULL);
		while ((*buf)[i++])
			rest[j++] = (*buf)[i];
		rest[j] = '\0';
		(*buf)[end] = '\0';
		return (rest);
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*rest;
	int			ret;
	int			back;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	back = 2;
	if (ft_check_rest(&rest, line) == 1)
		return (1);
	while (back == 2)
	{
		buf = ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		back = ft_endline(buf);
		if (ret == 0)
			back = 0;
		rest = ft_trac(rest, &buf);
		*line = ft_strclnjoin(*line, buf);
	}
	return (back);
}
