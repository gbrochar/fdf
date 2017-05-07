/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:05:43 by gbrochar          #+#    #+#             */
/*   Updated: 2016/03/12 08:43:46 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_manage_stock(char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		return (1);
	}
	*line = ft_strdup(*stock);
	free(*stock);
	return (0);
}

int		gnl_manage_read(char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*line, *stock);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		return (1);
	}
	*line = ft_strjoin(*line, *stock);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*stock = NULL;
	int				ret;

	if (stock)
		if (gnl_manage_stock(&stock, line))
			return (1);
	stock = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, stock, BUFF_SIZE)) > 0)
	{
		stock[ret] = '\0';
		if (gnl_manage_read(&stock, line))
			return (1);
	}
	return (ret);
}
