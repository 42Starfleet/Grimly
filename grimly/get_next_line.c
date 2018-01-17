/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:42:34 by husui             #+#    #+#             */
/*   Updated: 2017/12/24 14:43:39 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_line(const int fd, char **line, char *stock[4864])
{
	char		b[BUFF_SIZE + 1];
	char		*temp;
	int			n_read;

	while (!ft_strchr(stock[fd], '\n') && (n_read = read(fd, b, BUFF_SIZE)) > 0
			&& ft_memset(&b[n_read], 0, 1) && (temp = stock[fd]) &&
			(stock[fd] = ft_strjoin(temp, b)))
		free(temp);
	if (ft_strchr(stock[fd], '\n') && !(*ft_strchr(stock[fd], '\n') = 0))
	{
		temp = stock[fd];
		*line = ft_strdup(temp);
		stock[fd] = ft_strdup(ft_strchr(stock[fd], '\0') + 1);
		free(temp);
		return (1);
	}
	if (n_read < 0)
		return (-1);
	*line = stock[fd];
	if (!ft_strlen(*line) && !(*line = 0))
		return (0);
	*line = ft_strdup(stock[fd]);
	ft_memdel((void **)&stock[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stock[4864];
	char		test[1];
	int			result;

	if (fd < 0 || fd >= 4864 || line == 0 || read(fd, test, 0) == -1)
		return (-1);
	if (!stock[fd])
		stock[fd] = ft_strnew(0);
	result = read_line(fd, line, stock);
	if (result <= 0)
	{
		ft_memdel((void **)&stock[fd]);
		return (result);
	}
	return (1);
}
